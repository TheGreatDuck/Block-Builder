/*var i;
var j;

var blockDir1_x;
var blockDir1_y;
var blockDir1_z;

var blockDir2_x;
var blockDir2_y;
var blockDir2_z;

var blockDir3_x;
var blockDir3_y;
var blockDir3_z;

var blockDir4_x;
var blockDir4_y;
var blockDir4_z;

var blockRadius1_x;
var blockRadius1_y;
var blockRadius1_z;

var blockRadius2_x;
var blockRadius2_y;
var blockRadius2_z;

var blockRadius3_x;
var blockRadius3_y;
var blockRadius3_z;

var blockRadius4_x;
var blockRadius4_y;
var blockRadius4_z;

var blockNormal1_x;
var blockNormal1_y;
var blockNormal1_z;

var blockNormal2_x;
var blockNormal2_y;
var blockNormal2_z;

for (i = 0; i < numberOfBlockModels; i += 1)
{
    var v1x;
    var v1y;
    var v1z;
    
    var v2x;
    var v2y;
    var v2z;
    
    var v3x;
    var v3y;
    var v3z;
    
    var v4x;
    var v4x;
    var v4x;
    
    v1x = blockGraph[i,Block3D_v1x];
    v1y = blockGraph[i,Block3D_v1y];
    v1z = blockGraph[i,Block3D_v1z];
    v2x = blockGraph[i,Block3D_v2x];
    v2y = blockGraph[i,Block3D_v2y];
    v2z = blockGraph[i,Block3D_v2z];
    v3x = blockGraph[i,Block3D_v3x];
    v3y = blockGraph[i,Block3D_v3y];
    v3z = blockGraph[i,Block3D_v3z];
    v4x = blockGraph[i,Block3D_v4x];
    v4y = blockGraph[i,Block3D_v4y];
    v4z = blockGraph[i,Block3D_v4z];

    var commonLineDirection1_x;
    var commonLineDirection1_y;
    var commonLineDirection1_z;
    
    var commonLineDirection2_x;
    var commonLineDirection2_y;
    var commonLineDirection2_z;
    
    var commonLineDirection3_x;
    var commonLineDirection3_y;
    var commonLineDirection3_z;
    
    var commonLineDirection4_x;
    var commonLineDirection4_y;
    var commonLineDirection4_z;
    
    var norm1;
    var norm2;
    var norm3;
    var norm4;
    
    commonLineDirection1_x = v1x - v2x;
    commonLineDirection1_y = v1y - v2y;
    commonLineDirection1_z = v1z - v2z;
    
    commonLineDirection2_x = v2x - v4x;
    commonLineDirection2_y = v2y - v4y;
    commonLineDirection2_z = v2z - v4z;
    
    commonLineDirection3_x = v4x - v3x;
    commonLineDirection3_y = v4y - v3y;
    commonLineDirection3_z = v4z - v3z;
    
    commonLineDirection4_x = v3x - v1x;
    commonLineDirection4_y = v3y - v1y;
    commonLineDirection4_z = v3z - v1z;
    
    norm1 = sqrt(commonLineDirection1_x*commonLineDirection1_x + commonLineDirection1_y*commonLineDirection1_y + commonLineDirection1_z*commonLineDirection1_z);
    norm2 = sqrt(commonLineDirection2_x*commonLineDirection2_x + commonLineDirection2_y*commonLineDirection2_y + commonLineDirection2_z*commonLineDirection2_z);
    norm3 = sqrt(commonLineDirection3_x*commonLineDirection3_x + commonLineDirection3_y*commonLineDirection3_y + commonLineDirection3_z*commonLineDirection3_z);
    norm4 = sqrt(commonLineDirection4_x*commonLineDirection4_x + commonLineDirection4_y*commonLineDirection4_y + commonLineDirection4_z*commonLineDirection4_z);
    
    blockDir1_x[i] = commonLineDirection1_x/norm1;
    blockDir1_y[i] = commonLineDirection1_y/norm1;
    blockDir1_z[i] = commonLineDirection1_z/norm1;
    
    blockDir2_x[i] = commonLineDirection2_x/norm2;
    blockDir2_y[i] = commonLineDirection2_y/norm2;
    blockDir2_z[i] = commonLineDirection2_z/norm2;
    
    blockDir3_x[i] = commonLineDirection3_x/norm3;
    blockDir3_y[i] = commonLineDirection3_y/norm3;
    blockDir3_z[i] = commonLineDirection3_z/norm3;
    
    blockDir4_x[i] = commonLineDirection4_x/norm4;
    blockDir4_y[i] = commonLineDirection4_y/norm4;
    blockDir4_z[i] = commonLineDirection4_z/norm4;
    
    blockRadius1_x[i] = (-commonLineDirection2_x) - (blockDir1_x[i])*(-commonLineDirection2_x*blockDir1_x[i] - commonLineDirection2_y*blockDir1_y[i] - commonLineDirection2_z*blockDir1_z[i]);
    blockRadius1_y[i] = (-commonLineDirection2_y) - (blockDir1_y[i])*(-commonLineDirection2_x*blockDir1_x[i] - commonLineDirection2_y*blockDir1_y[i] - commonLineDirection2_z*blockDir1_z[i]);
    blockRadius1_z[i] = (-commonLineDirection2_z) - (blockDir1_z[i])*(-commonLineDirection2_x*blockDir1_x[i] - commonLineDirection2_y*blockDir1_y[i] - commonLineDirection2_z*blockDir1_z[i]);
    
    blockRadius2_x[i] = (commonLineDirection1_x) - (blockDir2_x[i])*(commonLineDirection1_x*blockDir2_x[i] + commonLineDirection1_y*blockDir2_y[i] + commonLineDirection1_z*blockDir2_z[i]);
    blockRadius2_y[i] = (commonLineDirection1_x) - (blockDir2_x[i])*(commonLineDirection1_x*blockDir2_x[i] + commonLineDirection1_y*blockDir2_y[i] + commonLineDirection1_z*blockDir2_z[i]);
    blockRadius2_z[i] = (commonLineDirection1_x) - (blockDir2_x[i])*(commonLineDirection1_x*blockDir2_x[i] + commonLineDirection1_y*blockDir2_y[i] + commonLineDirection1_z*blockDir2_z[i]);
    
    blockRadius3_x[i] = (-commonLineDirection4_x) - (blockDir3_x[i])*(-commonLineDirection4_x*blockDir3_x[i] - commonLineDirection4_y*blockDir3_y[i] - commonLineDirection4_z*blockDir3_z[i]);
    blockRadius3_y[i] = (-commonLineDirection4_x) - (blockDir3_x[i])*(-commonLineDirection4_x*blockDir3_x[i] - commonLineDirection4_y*blockDir3_y[i] - commonLineDirection4_z*blockDir3_z[i]);
    blockRadius3_z[i] = (-commonLineDirection4_x) - (blockDir3_x[i])*(-commonLineDirection4_x*blockDir3_x[i] - commonLineDirection4_y*blockDir3_y[i] - commonLineDirection4_z*blockDir3_z[i]);
    
    blockRadius4_x[i] = (commonLineDirection3_x) - (blockDir4_x[i])*(commonLineDirection3_x*blockDir4_x[i] + commonLineDirection3_y*blockDir4_y[i] - commonLineDirection3_z*blockDir4_z[i]);
    blockRadius4_y[i] = (commonLineDirection3_x) - (blockDir4_x[i])*(commonLineDirection3_x*blockDir4_x[i] + commonLineDirection3_y*blockDir4_y[i] - commonLineDirection3_z*blockDir4_z[i]);
    blockRadius4_z[i] = (commonLineDirection3_x) - (blockDir4_x[i])*(commonLineDirection3_x*blockDir4_x[i] + commonLineDirection3_y*blockDir4_y[i] - commonLineDirection3_z*blockDir4_z[i]);
    
    blockNormal1_x[i] = blockDir1_y[i]*blockDir2_z[i] - blockDir1_z[i]*blockDir2_y[i];
    blockNormal1_y[i] = blockDir1_z[i]*blockDir2_x[i] - blockDir1_x[i]*blockDir2_z[i];
    blockNormal1_z[i] = blockDir1_x[i]*blockDir2_y[i] - blockDir1_y[i]*blockDir2_x[i];
    
    blockNormal2_x[i] = blockDir3_y[i]*blockDir4_z[i] - blockDir3_z[i]*blockDir4_y[i];
    blockNormal2_y[i] = blockDir3_z[i]*blockDir4_x[i] - blockDir3_x[i]*blockDir4_z[i];
    blockNormal2_z[i] = blockDir3_x[i]*blockDir4_y[i] - blockDir3_y[i]*blockDir4_x[i];
}

for (i = 0; i < numberOfBlockModels; i += 1)
{
    var v1x;
    var v1y;
    var v1z;
    
    var v2x;
    var v2y;
    var v2z;
    
    var v3x;
    var v3y;
    var v3z;
    
    var v4x;
    var v4x;
    var v4x;
    
    v1x = blockGraph[i,Block3D_v1x];
    v1y = blockGraph[i,Block3D_v1y];
    v1z = blockGraph[i,Block3D_v1z];
    v2x = blockGraph[i,Block3D_v2x];
    v2y = blockGraph[i,Block3D_v2y];
    v2z = blockGraph[i,Block3D_v2z];
    v3x = blockGraph[i,Block3D_v3x];
    v3y = blockGraph[i,Block3D_v3y];
    v3z = blockGraph[i,Block3D_v3z];
    v4x = blockGraph[i,Block3D_v4x];
    v4y = blockGraph[i,Block3D_v4y];
    v4z = blockGraph[i,Block3D_v4z];
    
    var connectedBlock1;
    var connectedBlock2;
    var connectedBlock3;
    var connectedBlock4;
    
    connectedBlock1 = -1;
    connectedBlock2 = -1;
    connectedBlock3 = -1;
    connectedBlock4 = -1;
    
    var connectedBlockAngle1;
    var connectedBlockAngle2;
    var connectedBlockAngle3;
    var connectedBlockAngle4;
    
    connectedBlockAngle1 = 4*pi;
    connectedBlockAngle2 = 4*pi;
    connectedBlockAngle3 = 4*pi;
    connectedBlockAngle4 = 4*pi;

    var commonLineDirection1_x;
    var commonLineDirection1_y;
    var commonLineDirection1_z;
    
    var commonLineDirection2_x;
    var commonLineDirection2_y;
    var commonLineDirection2_z;
    
    var commonLineDirection3_x;
    var commonLineDirection3_y;
    var commonLineDirection3_z;
    
    var commonLineDirection4_x;
    var commonLineDirection4_y;
    var commonLineDirection4_z;
    
    var norm1;
    var norm2;
    var norm3;
    var norm4;
    
    commonLineDirection1_x = v1x - v2x;
    commonLineDirection1_y = v1y - v2y;
    commonLineDirection1_z = v1z - v2z;
    
    commonLineDirection2_x = v2x - v4x;
    commonLineDirection2_y = v2y - v4y;
    commonLineDirection2_z = v2z - v4z;
    
    commonLineDirection3_x = v4x - v3x;
    commonLineDirection3_y = v4y - v3y;
    commonLineDirection3_z = v4z - v3z;
    
    commonLineDirection4_x = v3x - v1x;
    commonLineDirection4_y = v3y - v1y;
    commonLineDirection4_z = v3z - v1z;
    
    norm1 = sqrt(commonLineDirection1_x*commonLineDirection1_x + commonLineDirection1_y*commonLineDirection1_y + commonLineDirection1_z*commonLineDirection1_z);
    norm2 = sqrt(commonLineDirection2_x*commonLineDirection2_x + commonLineDirection2_y*commonLineDirection2_y + commonLineDirection2_z*commonLineDirection2_z);
    norm3 = sqrt(commonLineDirection3_x*commonLineDirection3_x + commonLineDirection3_y*commonLineDirection3_y + commonLineDirection3_z*commonLineDirection3_z);
    norm4 = sqrt(commonLineDirection4_x*commonLineDirection4_x + commonLineDirection4_y*commonLineDirection4_y + commonLineDirection4_z*commonLineDirection4_z);
    
    commonLineDirection1_x /= norm1;
    commonLineDirection1_y /= norm1;
    commonLineDirection1_z /= norm1;
    
    commonLineDirection2_x /= norm2;
    commonLineDirection2_y /= norm2;
    commonLineDirection2_z /= norm2;
    
    commonLineDirection3_x /= norm3;
    commonLineDirection3_y /= norm3;
    commonLineDirection3_z /= norm3;
    
    commonLineDirection4_x /= norm4;
    commonLineDirection4_y /= norm4;
    commonLineDirection4_z /= norm4;
    
    dir1 
    
    for (j = 0; j < numberOfBlockModels; j += 1)
    {
        var p1x;
        var p1y;
        var p1z;
        
        var p2x;
        var p2y;
        var p2z;
        
        var p3x;
        var p3y;
        var p3z;
        
        var p4x;
        var p4x;
        var p4x;
        
        p1x = blockGraph[j,Block3D_v1x];
        p1y = blockGraph[j,Block3D_v1y];
        p1z = blockGraph[j,Block3D_v1z];
        p2x = blockGraph[j,Block3D_v2x];
        p2y = blockGraph[j,Block3D_v2y];
        p2z = blockGraph[j,Block3D_v2z];
        p3x = blockGraph[j,Block3D_v3x];
        p3y = blockGraph[j,Block3D_v3y];
        p3z = blockGraph[j,Block3D_v3z];
        p4x = blockGraph[j,Block3D_v4x];
        p4y = blockGraph[j,Block3D_v4y];
        p4z = blockGraph[j,Block3D_v4z];
        
        var pointEqual_11;
        var pointEqual_12;
        var pointEqual_13;
        var pointEqual_14;
        
        var pointEqual_21;
        var pointEqual_22;
        var pointEqual_23;
        var pointEqual_24;
        
        var pointEqual_31;
        var pointEqual_32;
        var pointEqual_33;
        var pointEqual_34;
        
        var pointEqual_41;
        var pointEqual_42;
        var pointEqual_43;
        var pointEqual_44;
        
        pointEqual_11 = (p1x == v1x && p1y == v1y && p1z == v1z);
        pointEqual_12 = (p1x == v2x && p1y == v2y && p1z == v2z);
        pointEqual_13 = (p1x == v3x && p1y == v3y && p1z == v3z);
        pointEqual_14 = (p1x == v4x && p1y == v4y && p1z == v4z);
        
        pointEqual_21 = (p2x == v1x && p2y == v1y && p2z == v1z);
        pointEqual_22 = (p2x == v2x && p2y == v2y && p2z == v2z);
        pointEqual_23 = (p2x == v3x && p2y == v3y && p2z == v3z);
        pointEqual_24 = (p2x == v4x && p2y == v4y && p2z == v4z);
        
        pointEqual_31 = (p3x == v1x && p3y == v1y && p3z == v1z);
        pointEqual_32 = (p3x == v2x && p3y == v2y && p3z == v2z);
        pointEqual_33 = (p3x == v3x && p3y == v3y && p3z == v3z);
        pointEqual_34 = (p3x == v4x && p3y == v4y && p3z == v4z);
        
        pointEqual_41 = (p4x == v1x && p4y == v1y && p4z == v1z);
        pointEqual_42 = (p4x == v2x && p4y == v2y && p4z == v2z);
        pointEqual_43 = (p4x == v3x && p4y == v3y && p4z == v3z);
        pointEqual_44 = (p4x == v4x && p4y == v4y && p4z == v4z);
        
        //side 1
        if (pointEqual_21 && pointEqual_12)
        {
            var n1x;
            var n1y;
            var n1z;
            
            var n2x;
            var n2y;
            var n2z;
            
            public static double triangleAngle(Triangle t1, Triangle t2, 1, 1)//, Model model)
            {
                //adjust to the corresponding vertices
                int i1 = (connection1 + 1) % 3;
                int i2 = (connection2 + 1) % 3;
                
                Vector p1 = new Vector(t1.vertexList.get(i1));
                Vector p2 = new Vector(t2.vertexList.get(i2));
                
                if (t1.vertexList.get(i1).equalPosition(t2.vertexList.get(i2)))
                {
                    return 360;
                }
                
                Vector v1 = new Vector(t1.vertexList.get((i1+1)%3));
                Vector v2 = new Vector(t1.vertexList.get((i1+2)%3));
                
                Vector commonLineDirection = v1.minus(v2).normalize();
                
                p1 = p1.minus(v2);
                p2 = p2.minus(v2);
                
                p1 = p1.minus(commonLineDirection.times(p1.dotProduct(commonLineDirection)));
                p2 = p2.minus(commonLineDirection.times(p2.dotProduct(commonLineDirection)));
                
                p1 = p1.normalize();
                p2 = p2.normalize();
                
                Vector n1 = t1.unitNormal();
                Vector n2 = t2.unitNormal();
                
                Vector n3 = n1.plus(n2);
                n3 = n3.normalize();
                
                return (Math.acos(p1.dotProduct(n3)) + Math.acos(p2.dotProduct(n3)))*(180.0/Math.PI);
            }
        } else if (pointEqual_41 && pointEqual_22)
        {
            
        } else if (pointEqual_31 && pointEqual_42)
        {
            
        } else if (pointEqual_11 && pointEqual_32)
        {
            
        }
        
        //side 2
        if (pointEqual_22 && pointEqual_14)
        {
        
        } else if (pointEqual_42 && pointEqual_24)
        {
        
        } else if (pointEqual_32 && pointEqual_44)
        {
        
        } else if (pointEqual_12 && pointEqual_34)
        {
        
        }
        
        //side 3
        if (pointEqual_24 && pointEqual_13)
        {
        
        } else if (pointEqual_44 && pointEqual_23)
        {
        
        } else if (pointEqual_34 && pointEqual_43)
        {
        
        } else if (pointEqual_14 && pointEqual_33)
        {
        
        }
        
        //side 4
        if (pointEqual_23 && pointEqual_11)
        {
        
        } else if (pointEqual_43 && pointEqual_21)
        {
        
        } else if (pointEqual_33 && pointEqual_41)
        {
        
        } else if (pointEqual_13 && pointEqual_31)
        {
        
        }
    }
}*/
