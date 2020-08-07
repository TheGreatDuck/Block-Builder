for (i = 0; i < numberOfSegments-1; i+=1)
{
    directions_x[i] = points_x[i+1] - points_x[i];
    directions_y[i] = points_y[i+1] - points_y[i];
    directions_z[i] = points_z[i+1] - points_z[i];
    norm = sqrt(directions_x[i]*directions_x[i] + directions_y[i]*directions_y[i] + directions_z[i]*directions_z[i]);
}
