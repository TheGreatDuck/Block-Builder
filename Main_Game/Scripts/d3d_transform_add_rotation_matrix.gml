var a11; var a12; var a13;
var a21; var a22; var a23;
var a31; var a32; var a33;

a11 = argument[0]; a12 = argument[1]; a13 = argument[2];
a21 = argument[3]; a22 = argument[4]; a23 = argument[5];
a31 = argument[6]; a32 = argument[7]; a33 = argument[8];

//show_message(string(a11) + "   " + string(a12) + "   " + string(a13) + "#" + string(a21) + "   " + string(a22) + "   " + string(a23) + "#" + string(a31) + "   " + string(a32) + "   " + string(a33));

var rot_x; var rot_y; var rot_z; var rot_angle;
if ((a11 + a22 + a33 - 1)/2 > 1)
{
    rot_angle = 0;
} else if ((a11 + a22 + a33 - 1)/2 < -1)
{
    rot_angle = pi;
} else
{
    rot_angle = arccos((a11 + a22 + a33 - 1)/2);
}

if (sin(rot_angle) != 0)
{
    rot_x = (a32 - a23)/(2*sin(rot_angle));
    rot_y = (a13 - a31)/(2*sin(rot_angle));
    rot_z = (a21 - a12)/(2*sin(rot_angle));
} else if (cos(rot_angle) == 1)
{
    rot_x = 0;
    rot_y = 0;
    rot_z = 1;
} else
{
    var rot_norm;
    rot_x = 2*a11 + 2;
    rot_y = a12 + a21;
    rot_z = a13 + a31;
    rot_norm = sqrt(rot_x*rot_x + rot_y*rot_y + rot_z*rot_z);
    if (rot_norm == 0)
    {
        rot_x = a21 + a12;
        rot_y = 2*a22 + 2;
        rot_z = a32 + a23;
        rot_norm = sqrt(rot_x*rot_x + rot_y*rot_y + rot_z*rot_z);
    }
    
    if (rot_norm == 0)
    {
        rot_x = a31 + a13;
        rot_y = a32 + a23;
        rot_z = 2*a33 + 2;
        rot_norm = sqrt(rot_x*rot_x + rot_y*rot_y + rot_z*rot_z);
    }
    rot_x /= rot_norm;
    rot_y /= rot_norm;
    rot_z /= rot_norm;
}

rot_angle = (2*(rot_angle == pi) - 1)*rot_angle*(180/pi);
//show_message(string(rot_x) + " " + string(rot_y) + " " + string(rot_z) + " " + string(rot_angle));
d3d_transform_add_rotation_axis(rot_x,rot_y,rot_z,rot_angle);
