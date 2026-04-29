#include <GL/freeglut.h>
#include <cmath>
#include <vector>

struct PointF {
	float x;
	float y;
};

struct PointI {
	int x;
	int y;
};

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const float BORDER_COLOR[3] = {0.0f, 0.0f, 0.0f};
const float CIRCLE_FILL_COLOR[3] = {0.1f, 0.7f, 0.95f};
const float TRIANGLE_FILL_COLOR[3] = {0.95f, 0.8f, 0.2f};

const PointF TRI_ORIG[3] = {
	{270.0f, 188.0f},
	{530.0f, 188.0f},
	{400.0f, 417.0f}
};

float rotationAngleDeg = 0.0f;
float scaleFactor = 1.0f;

bool circleFilled = false;
bool triangleFilled = false;

PointF triTransformed[3];
PointF triCentroid;
float circleRadiusBase = 40.0f;
float circleRadiusTransformed = 40.0f;

float absf(float v) {
	return (v < 0.0f) ? -v : v;
}

void setPixel(int x, int y, const float color[3]) {
	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT) {
		return;
	}
	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void getPixel(int x, int y, float out[3]) {
	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT) {
		out[0] = 1.0f;
		out[1] = 1.0f;
		out[2] = 1.0f;
		return;
	}
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, out);
}

bool sameColor(const float a[3], const float b[3], float eps = 0.02f) {
	return absf(a[0] - b[0]) <= eps && absf(a[1] - b[1]) <= eps && absf(a[2] - b[2]) <= eps;
}

PointF computeCentroid(const PointF tri[3]) {
	PointF c;
	c.x = (tri[0].x + tri[1].x + tri[2].x) / 3.0f;
	c.y = (tri[0].y + tri[1].y + tri[2].y) / 3.0f;
	return c;
}

PointF transformAroundPivot(const PointF &p, const PointF &pivot, float angleDeg, float scale) {
	float rad = angleDeg * 3.14159265358979323846f / 180.0f;
	float c = std::cos(rad);
	float s = std::sin(rad);

	float tx = p.x - pivot.x;
	float ty = p.y - pivot.y;

	tx *= scale;
	ty *= scale;

	PointF out;
	out.x = pivot.x + (tx * c - ty * s);
	out.y = pivot.y + (tx * s + ty * c);
	return out;
}

float cross(const PointF &a, const PointF &b, const PointF &p) {
	return (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);
}

bool pointInTriangle(const PointF &p, const PointF tri[3]) {
	float c1 = cross(tri[0], tri[1], p);
	float c2 = cross(tri[1], tri[2], p);
	float c3 = cross(tri[2], tri[0], p);

	bool hasNeg = (c1 < -0.001f) || (c2 < -0.001f) || (c3 < -0.001f);
	bool hasPos = (c1 > 0.001f) || (c2 > 0.001f) || (c3 > 0.001f);
	return !(hasNeg && hasPos);
}

bool pointInCircle(const PointF &p, const PointF &center, float radius) {
	float dx = p.x - center.x;
	float dy = p.y - center.y;
	return (dx * dx + dy * dy) <= (radius * radius);
}

void updateTransformedGeometry() {
	PointF pivot = {0.0f, 0.0f};

	triTransformed[0] = transformAroundPivot(TRI_ORIG[0], pivot, rotationAngleDeg, scaleFactor);
	triTransformed[1] = transformAroundPivot(TRI_ORIG[1], pivot, rotationAngleDeg, scaleFactor);
	triTransformed[2] = transformAroundPivot(TRI_ORIG[2], pivot, rotationAngleDeg, scaleFactor);

	triCentroid = computeCentroid(triTransformed);
	circleRadiusTransformed = circleRadiusBase * scaleFactor;
}

void bresenhamLine(int x1, int y1, int x2, int y2, const float color[3]) {
	int dx = x2 - x1;
	int dy = y2 - y1;

	int incX = (dx >= 0) ? 1 : -1;
	int incY = (dy >= 0) ? 1 : -1;

	dx = std::abs(dx);
	dy = std::abs(dy);

	int x = x1;
	int y = y1;
	setPixel(x, y, color);

	if (dx > dy) {
		int p = 2 * dy - dx;
		for (int i = 0; i < dx; ++i) {
			x += incX;
			if (p < 0) {
				p += 2 * dy;
			} else {
				y += incY;
				p += 2 * (dy - dx);
			}
			setPixel(x, y, color);
		}
	} else {
		int p = 2 * dx - dy;
		for (int i = 0; i < dy; ++i) {
			y += incY;
			if (p < 0) {
				p += 2 * dx;
			} else {
				x += incX;
				p += 2 * (dx - dy);
			}
			setPixel(x, y, color);
		}
	}
}

void plotCircleSymmetricPoints(int xc, int yc, int x, int y, const float color[3]) {
	PointI pts[8] = {
		{xc + x, yc + y},
		{xc - x, yc + y},
		{xc + x, yc - y},
		{xc - x, yc - y},
		{xc + y, yc + x},
		{xc - y, yc + x},
		{xc + y, yc - x},
		{xc - y, yc - x}
	};

	for (int i = 0; i < 8; ++i) {
		PointF p = {static_cast<float>(pts[i].x), static_cast<float>(pts[i].y)};
		if (pointInTriangle(p, triTransformed)) {
			setPixel(pts[i].x, pts[i].y, color);
		}
	}
}

void midPointCircle(int xc, int yc, int radius, const float color[3]) {
	int x = 0;
	int y = radius;
	int decision = 1 - radius;

	while (x <= y) {
		plotCircleSymmetricPoints(xc, yc, x, y, color);
		++x;
		if (decision < 0) {
			decision += 2 * x + 1;
		} else {
			--y;
			decision += 2 * (x - y) + 1;
		}
	}
}

void drawTriangleEdges(const PointF tri[3], const float color[3]) {
	bresenhamLine(static_cast<int>(std::round(tri[0].x)), static_cast<int>(std::round(tri[0].y)),
				  static_cast<int>(std::round(tri[1].x)), static_cast<int>(std::round(tri[1].y)), color);
	bresenhamLine(static_cast<int>(std::round(tri[1].x)), static_cast<int>(std::round(tri[1].y)),
				  static_cast<int>(std::round(tri[2].x)), static_cast<int>(std::round(tri[2].y)), color);
	bresenhamLine(static_cast<int>(std::round(tri[2].x)), static_cast<int>(std::round(tri[2].y)),
				  static_cast<int>(std::round(tri[0].x)), static_cast<int>(std::round(tri[0].y)), color);
}

PointI findTriangleSeedOutsideCircle() {
	PointF candidates[3] = {
		{triCentroid.x * 0.25f + triTransformed[0].x * 0.75f, triCentroid.y * 0.25f + triTransformed[0].y * 0.75f},
		{triCentroid.x * 0.25f + triTransformed[1].x * 0.75f, triCentroid.y * 0.25f + triTransformed[1].y * 0.75f},
		{triCentroid.x * 0.25f + triTransformed[2].x * 0.75f, triCentroid.y * 0.25f + triTransformed[2].y * 0.75f}
	};

	for (int i = 0; i < 3; ++i) {
		if (pointInTriangle(candidates[i], triTransformed) &&
			!pointInCircle(candidates[i], triCentroid, circleRadiusTransformed)) {
			return {static_cast<int>(std::round(candidates[i].x)), static_cast<int>(std::round(candidates[i].y))};
		}
	}

	for (int i = 0; i < 3; ++i) {
		PointF p = {triCentroid.x * 0.1f + triTransformed[i].x * 0.9f, triCentroid.y * 0.1f + triTransformed[i].y * 0.9f};
		if (pointInTriangle(p, triTransformed) && !pointInCircle(p, triCentroid, circleRadiusTransformed)) {
			return {static_cast<int>(std::round(p.x)), static_cast<int>(std::round(p.y))};
		}
	}

	return {static_cast<int>(std::round(triTransformed[0].x)), static_cast<int>(std::round(triTransformed[0].y))};
}

void boundaryFill4(int sx, int sy, const float fillColor[3], const float borderColor[3]) {
	std::vector<PointI> stack;
	stack.push_back({sx, sy});

	while (!stack.empty()) {
		PointI p = stack.back();
		stack.pop_back();

		if (p.x < 0 || p.x >= WINDOW_WIDTH || p.y < 0 || p.y >= WINDOW_HEIGHT) {
			continue;
		}

		float cur[3];
		getPixel(p.x, p.y, cur);

		if (sameColor(cur, borderColor) || sameColor(cur, fillColor)) {
			continue;
		}

		setPixel(p.x, p.y, fillColor);

		stack.push_back({p.x + 1, p.y});
		stack.push_back({p.x - 1, p.y});
		stack.push_back({p.x, p.y + 1});
		stack.push_back({p.x, p.y - 1});
	}
}

void applyRequestedFills() {
	if (triangleFilled) {
		PointI seedTri = findTriangleSeedOutsideCircle();
		boundaryFill4(seedTri.x, seedTri.y, TRIANGLE_FILL_COLOR, BORDER_COLOR);
	}

	if (circleFilled) {
		int sx = static_cast<int>(std::round(triCentroid.x));
		int sy = static_cast<int>(std::round(triCentroid.y));
		boundaryFill4(sx, sy, CIRCLE_FILL_COLOR, BORDER_COLOR);
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	updateTransformedGeometry();

	drawTriangleEdges(triTransformed, BORDER_COLOR);
	midPointCircle(static_cast<int>(std::round(triCentroid.x)),
				   static_cast<int>(std::round(triCentroid.y)),
				   static_cast<int>(std::round(circleRadiusTransformed)),
				   BORDER_COLOR);

	applyRequestedFills();

	glFlush();
}

void mouse(int button, int state, int x, int y) {
	if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN) {
		return;
	}

	PointF p = {static_cast<float>(x), static_cast<float>(WINDOW_HEIGHT - y)};

	if (pointInCircle(p, triCentroid, circleRadiusTransformed)) {
		circleFilled = true;
	} else if (pointInTriangle(p, triTransformed)) {
		triangleFilled = true;
	}

	glutPostRedisplay();
}

void menuHandler(int option) {
	switch (option) {
		case 1:
			rotationAngleDeg += 15.0f;
			break;
		case 2:
			rotationAngleDeg -= 15.0f;
			break;
		case 3:
			scaleFactor *= 1.1f;
			if (scaleFactor > 2.5f) {
				scaleFactor = 2.5f;
			}
			break;
		case 4:
			scaleFactor *= 0.9f;
			if (scaleFactor < 0.45f) {
				scaleFactor = 0.45f;
			}
			break;
		case 5:
			rotationAngleDeg = 0.0f;
			scaleFactor = 1.0f;
			circleFilled = false;
			triangleFilled = false;
			break;
		case 6:
			std::exit(0);
			break;
		default:
			break;
	}

	glutPostRedisplay();
}

void init() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPointSize(1.0f);

	updateTransformedGeometry();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(100, 80);
	glutCreateWindow("Triangle + Midpoint Circle + Boundary Fill + Transform");

	init();

	glutDisplayFunc(display);
	glutMouseFunc(mouse);

	glutCreateMenu(menuHandler);
	glutAddMenuEntry("Rotate +15 deg", 1);
	glutAddMenuEntry("Rotate -15 deg", 2);
	glutAddMenuEntry("Scale Up", 3);
	glutAddMenuEntry("Scale Down", 4);
	glutAddMenuEntry("Reset", 5);
	glutAddMenuEntry("Exit", 6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
	return 0;
}