

typedef struct player3D
{
    unsigned int type;
    unsigned int blockLeftPressed;
    unsigned int blockRightPressed;

    unsigned int currentSpace;
    unsigned int sideFacing;
    unsigned int sideFacingAfter;
    unsigned int moving;
    unsigned int motion;
    unsigned int movingSpace;
    unsigned int movingSideOne;
    unsigned int movingSideTwo;

    vector position;

    vector axisX;

    vector dir;

    vector n;

    double spin;

    int texBody;
    int texEye;
} player3D;

extern player3D player;

GMEXPORT double d3d_transform_add_rotation_matrix(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33);
GMEXPORT double player3D_moveInDirection(double double_sideMoving);
GMEXPORT double player3D_moveInDirectionWithoutCollision(double double_sideMoving);
GMEXPORT double player3D_drawEvent();
GMEXPORT double player3D_stepEvent();
