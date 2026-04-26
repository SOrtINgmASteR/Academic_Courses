// Transformations (Scale, Rotate, Translate) + Undo + Reset
// using a circular array (ring buffer) of transform_state with max history N.

#include <GL/freeglut.h>
#include <GL/glut.h>

typedef struct {
    float rotation_angle; // degrees
    float scale_factor;   // uniform scale
    float translate_x;
    float translate_y;
} transform_state;

const GLfloat tri[3][2] = {
    {0.1f, 0.4f},
    {0.7f, 0.4f},
    {0.4f, 0.8f}
};

// Maximum history size (N)
static constexpr int N = 3;

// Ring buffer storage
transform_state history[N];

// Ring buffer bookkeeping
int head = 0;     // index of oldest element in the ring
int count = 0;    // number of valid elements (0..N)
int current = -1; // current position as an offset from head (0..count-1), -1 means no state

static inline int ringIndex(int offsetFromHead) {
    // offsetFromHead in [0, N-1]
    return (head + offsetFromHead) % N;
}

transform_state identityState() {
    transform_state s;
    s.rotation_angle = 0.0f;
    s.scale_factor   = 1.0f;
    s.translate_x    = 0.0f;
    s.translate_y    = 0.0f;
    return s;
}

transform_state getCurrentStateOrIdentity() {
    if (current < 0 || count == 0) return identityState();
    return history[ringIndex(current)];
}

void resetHistory() {
    head = 0;
    count = 0;
    current = -1;
}

void pushState(const transform_state& s) {
    // If we undid and then apply a new transform, drop "future" history
    if (current >= 0 && current < count - 1) {
        count = current + 1;
        // head stays the same; we just consider fewer elements valid
    }

    if (count < N) {
        // append at end
        history[ringIndex(count)] = s;
        count++;
        current = count - 1;
    } else {
        // buffer full: overwrite oldest
        // oldest is at head; new element goes to "end", which is also head when full
        history[head] = s;
        head = (head + 1) % N; // move oldest forward
        current = count - 1;   // remain at newest (still count-1)
    }
}

void undo() {
    if (current >= 0) current--;
}

void drawTriangle() {
    glBegin(GL_POLYGON);
    glVertex2f(tri[0][0], tri[0][1]);
    glVertex2f(tri[1][0], tri[1][1]);
    glVertex2f(tri[2][0], tri[2][1]);
    glEnd();
}

void applyStateToModelView(const transform_state& s) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(s.translate_x, s.translate_y, 0.0f);
    glTranslatef(0.1f, 0.4f, 0.0f);
    glRotatef(s.rotation_angle, 0.0f, 0.0f, 1.0f);
    glScalef(s.scale_factor, s.scale_factor, 1.0f);
    glTranslatef(-0.1f, -0.4f, 0.0f);
}

void applyRotation() {
    transform_state s = getCurrentStateOrIdentity();
    s.rotation_angle += 45.0f;
    pushState(s);
}

void applyScaling() {
    transform_state s = getCurrentStateOrIdentity();
    s.scale_factor *= 1.5f;
    pushState(s);
}

void applyTranslation() {
    transform_state s = getCurrentStateOrIdentity();
    s.translate_x += 0.2f;
    s.translate_y += 0.1f;
    pushState(s);
}

void option_menu(GLint option) {
    switch (option) {
        case 1: applyRotation(); break;
        case 2: applyScaling(); break;
        case 3: applyTranslation(); break;
        case 4: undo(); break;
        case 5: resetHistory(); break;
        default: break;
    }
    glutPostRedisplay();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Start with a baseline identity state in history so first undo works predictably
    pushState(identityState());
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Apply current state (or identity if none)
    applyStateToModelView(getCurrentStateOrIdentity());

    glColor3f(1.0f, 0.2f, 0.0f);
    drawTriangle();

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Transformations + Undo (Circular History)");

    init();
    glutDisplayFunc(display);

    glutCreateMenu(option_menu);
    glutAddMenuEntry("Rotate", 1);
    glutAddMenuEntry("Scale", 2);
    glutAddMenuEntry("Translate", 3);
    glutAddMenuEntry("Undo", 4);
    glutAddMenuEntry("Reset", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}