#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream> 
#include <cstdlib>  
#include <GLAD/KHR/khrplatform.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <camera.h>

// Function for creating the first cylinder with texture and liquid inside the cup
void renderCylinder(float x1, float y1, float z1, float x2, float y2, float z2, float radius, const char* texture_path)
{
    glPushMatrix();
    glTranslatef(x1, y1, z1);
    glRotatef(atan2(z2 - z1, y2 - y1) * 180 / M_PI, 0, 1, 0);
    glRotatef(atan2(sqrt(pow(z2 - z1, 2) + pow(y2 - y1, 2)), x2 - x1) * 180 / M_PI, 0, 0, 1);

    // Load texture using stb_image
    int width, height, num_channels;
    unsigned char* data = stbi_load("../testcup.png", &width, &height, &num_channels, 0);

    // Create texture object 
    GLuint texture_id;
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);

    // Set texture parameters 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Upload texture data to GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    stbi_image_free(data);

    // Enable texture mapping
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_id);

    // Render cylinder with texture 
    GLUquadricObj* cylinder = gluNewQuadric();
    gluQuadricDrawStyle(cylinder, GLU_FILL);
    gluQuadricTexture(cylinder, GL_TRUE);
    gluCylinder(cylinder, radius * 1.5f, radius * 1.5f, sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2)) * 0.5f, 16, 1);

    // Disable texture mapping
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

// Function for creating the second cylinder with texture
void renderCylinderTwo(float x1, float y1, float z1, float x2, float y2, float z2, float radius, const char* texture_path)
{
    glPushMatrix();
    glTranslatef(x1, y1, z1);
    glRotatef(atan2(z2 - z1, y2 - y1) * 180 / M_PI, 0, 1, 0);
    glRotatef(atan2(sqrt(pow(z2 - z1, 2) + pow(y2 - y1, 2)), x2 - x1) * 180 / M_PI, 0, 0, 1);

    // Load texture using stb_image
    int width, height, num_channels;
    unsigned char* data = stbi_load("../testcup.png", &width, &height, &num_channels, 0);

    // Create texture object 
    GLuint texture_id;
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);

    // Set texture parameters 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Upload texture data to GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    stbi_image_free(data);

    // Enable texture mapping
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_id);

    // Render cylinder with texture 
    GLUquadricObj* cylinder = gluNewQuadric();
    gluQuadricDrawStyle(cylinder, GLU_FILL);
    gluQuadricTexture(cylinder, GL_TRUE);
    gluCylinder(cylinder, radius * 1.5f, radius * 1.5f, sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2)) * 0.68f, 16, 1);

    // Disable texture mapping
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

// Function for creating the third cylinder
void renderCylinderThree(float x1, float y1, float z1, float x2, float y2, float z2, float radius, const char* texture_path)
{
    glPushMatrix();
    glTranslatef(x1, y1, z1);
    glRotatef(atan2(z2 - z1, y2 - y1) / M_PI, 0, 1, 0);
    glRotatef(atan2(sqrt(pow(z2 - z1, 2) + pow(y2 - y1, 2)), x2 - x1) * 180 / M_PI, 0, 0, 1);

    // Load texture using stb_image
    int width, height, num_channels;
    unsigned char* data = stbi_load("../teacup.png", &width, &height, &num_channels, 0);

    // Create texture object 
    GLuint texture_id;
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);

    // Set texture parameters 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Upload texture data to GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    stbi_image_free(data);

    // Enable texture mapping
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_id);

    // Render cylinder with texture 
    GLUquadricObj* cylinder = gluNewQuadric();
    gluQuadricDrawStyle(cylinder, GLU_FILL);
    gluQuadricTexture(cylinder, GL_TRUE);
    gluCylinder(cylinder, radius * 1.5f, radius * 1.5f, sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2)) * 0.68f, 16, 1);

    // Load texture image for torus ring using stb_image
    int torus_width, torus_height, torus_channels;
    unsigned char* torus_texture_data = stbi_load("../accent.png", &torus_width, &torus_height, &torus_channels, STBI_rgb_alpha);

    // Generate texture ID for torus ring texture
    GLuint torus_texture_id;
    glGenTextures(1, &torus_texture_id);

    // Bind texture for torus ring
    glBindTexture(GL_TEXTURE_2D, torus_texture_id);

    // Set texture parameters for torus ring texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    // Load texture data for torus ring texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, torus_width, torus_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, torus_texture_data);

    // Free texture data for torus ring
    stbi_image_free(torus_texture_data);

    // Bind texture before rendering the torus ring
    glBindTexture(GL_TEXTURE_2D, torus_texture_id);

    // Draw torus ring at the top of the cylinder
    glPushMatrix();
    glTranslatef(-0.35, 0, 1.59); // translate to the top of the cylinder
    glRotatef(360, 1, 0, 0);

    // Set torus ring parameters
    GLfloat torus_radius = 0.90;
    GLfloat torus_thickness = 0.20;
    GLint torus_sides = 32;
    GLint torus_rings = 8;

    // Draw torus ring
    GLUquadricObj* quadric = gluNewQuadric();
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluQuadricTexture(quadric, GL_TRUE);
    glPushMatrix();
    glTranslatef(0.35, 0, -torus_thickness / 2); // translate to center of torus ring
    gluQuadricTexture(quadric, GL_TRUE);
    gluDisk(quadric, torus_radius - torus_thickness, torus_radius, torus_sides, 1);
    gluQuadricTexture(quadric, GL_FALSE);
    gluCylinder(quadric, torus_radius, torus_radius, torus_thickness, torus_sides, torus_rings);
    glTranslatef(0, 0, torus_thickness); // translate to other end of torus ring
    gluQuadricTexture(quadric, GL_TRUE);
    gluDisk(quadric, torus_radius - torus_thickness, torus_radius, torus_sides, 1);
    glPopMatrix();
    gluDeleteQuadric(quadric);
    glPopMatrix();

    GLfloat disk_radius = 0.80;
    GLfloat disk_thickness = 0.05;

    int disk_texture_width, disk_texture_height, disk_texture_channels;
    unsigned char* disk_texture_data = stbi_load("../accent.png", &disk_texture_width, &disk_texture_height, &disk_texture_channels, STBI_rgb_alpha);

    // Generate texture ID for disk texture
    GLuint disk_texture_id;
    glGenTextures(1, &disk_texture_id);

    // Bind texture for disk
    glBindTexture(GL_TEXTURE_2D, disk_texture_id);

    // Set texture parameters for disk texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    // Load texture data for disk texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, disk_texture_width, disk_texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, disk_texture_data);

    // Free texture data for disk
    stbi_image_free(disk_texture_data);

    // Enable texture mapping for disk
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, disk_texture_id);

    // Draw disk at the top of the torus
    glPushMatrix();
    glTranslatef(0.0, 0.0, 1.67);
    glRotatef(180, 1, 0, 0);

    GLUquadricObj* disk_quadric = gluNewQuadric();
    gluQuadricNormals(disk_quadric, GLU_SMOOTH);
    gluQuadricTexture(disk_quadric, GL_TRUE);
    gluDisk(disk_quadric, 0, disk_radius, 32, 1);
    gluCylinder(disk_quadric, disk_radius, disk_radius, disk_thickness, 32, 1);
    glTranslatef(0, 0, disk_thickness);
    gluDisk(disk_quadric, 0, disk_radius, 32, 1);
    gluDeleteQuadric(disk_quadric);
    glPopMatrix();

    // Disable texture mapping
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

// Function for creating the disk with texture
void renderDisk(float x, float y, float z, float inner_radius, float outer_radius, const char* texture_file)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    GLUquadricObj* disk = gluNewQuadric();
    gluQuadricDrawStyle(disk, GLU_FILL);

    // Load texture 
    int width, height, channels;
    unsigned char* image = stbi_load("../disk.png", &width, &height, &channels, STBI_rgb_alpha);

    // Generate texture ID 
    GLuint textureID;
    glGenTextures(1, &textureID);

    // Bind texture 
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Set texture parameters 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Set texture data 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

    // Enable texture 
    glEnable(GL_TEXTURE_2D);

    // Apply texture to disk 
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(0, 0, 0);
    for (int i = 0; i <= 16; i++)
    {
        float angle = i * (2.0f * M_PI / 16);
        float x = outer_radius * cos(angle);
        float y = outer_radius * sin(angle);
        glTexCoord2f((x / outer_radius + 1.0f) / 2.0f, (y / outer_radius + 1.0f) / 2.0f);
        glVertex3f(x, y, 0);
    }
    glEnd();


    // Load texture image for torus ring using stb_image
    int torus_width, torus_height, torus_channels;
    unsigned char* torus_texture_data = stbi_load("../disk.png", &torus_width, &torus_height, &torus_channels, STBI_rgb_alpha);

    // Generate texture ID for torus ring texture
    GLuint torus_texture_id;
    glGenTextures(1, &torus_texture_id);

    // Bind texture for torus ring
    glBindTexture(GL_TEXTURE_2D, torus_texture_id);

    // Set texture parameters for torus ring texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    // Load texture data for torus ring texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, torus_width, torus_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, torus_texture_data);

    // Free texture data for torus ring
    stbi_image_free(torus_texture_data);

    // Bind texture before rendering the torus ring
    glBindTexture(GL_TEXTURE_2D, torus_texture_id);

    // Draw torus ring at the top of the disk
    glPushMatrix();
    glTranslatef(-0.35, 0, 0.09); // translate to the top of the sphere
    glRotatef(360, 1, 0, 0); // rotate to be parallel with the XY plane

    // Set torus ring parameters
    GLfloat torus_radius = 2.50;
    GLfloat torus_thickness = 0.15;
    GLint torus_sides = 32;
    GLint torus_rings = 8;

    // Draw torus ring
    GLUquadricObj* quadric = gluNewQuadric();
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluQuadricTexture(quadric, GL_TRUE);
    glPushMatrix();
    glTranslatef(0.35, 0, -torus_thickness / 2); 
    gluQuadricTexture(quadric, GL_TRUE);
    gluDisk(quadric, torus_radius - torus_thickness, torus_radius, torus_sides, 1);
    gluQuadricTexture(quadric, GL_FALSE);
    gluCylinder(quadric, torus_radius, torus_radius, torus_thickness, torus_sides, torus_rings);
    glTranslatef(0, 0, torus_thickness);
    gluQuadricTexture(quadric, GL_TRUE);
    gluDisk(quadric, torus_radius - torus_thickness, torus_radius, torus_sides, 1);
    glPopMatrix();
    gluDeleteQuadric(quadric);
    glPopMatrix();

    // Disable texture
    glDisable(GL_TEXTURE_2D);

    /* Free image data */
    stbi_image_free(image);

    gluDeleteQuadric(disk);
    glPopMatrix();
}

// Function for creating the sphere with texture
void renderSphere()
{
    int i, j;
    int lats = 16;
    int longs = 16;

    // Load texture image using stb_image
    int width, height, channels;
    unsigned char* texture_data = stbi_load("../teacup.png", &width, &height, &channels, STBI_rgb_alpha);

    // Generate texture ID
    GLuint texture_id;
    glGenTextures(1, &texture_id);

    // Bind texture
    glBindTexture(GL_TEXTURE_2D, texture_id);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    // Load texture data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture_data);

    // Free texture data
    stbi_image_free(texture_data);

    // Enable texturing
    glEnable(GL_TEXTURE_2D);

    // Bind texture before rendering the sphere
    glBindTexture(GL_TEXTURE_2D, texture_id);

    glPushMatrix();
    glScalef(1.0, 0.75, 2.0); // Scale in Z direction
    for (i = 0; i <= lats; i++) {
        if (i >= lats / 2) { // Check if latitude is greater than or equal to half of total latitudes
            double lat0 = M_PI * (-0.5 + (double)(i - 1) / lats);
            double z0 = sin(lat0);
            double zr0 = cos(lat0);

            double lat1 = M_PI * (-0.5 + (double)i / lats);
            double z1 = sin(lat1);
            double zr1 = cos(lat1);

            glBegin(GL_QUAD_STRIP);
            for (j = 0; j <= longs; j++) {
                double lng = 2 * M_PI * (double)(j - 1) / longs;
                double x = cos(lng);
                double y = sin(lng);

                glNormal3f(x * zr0, y * zr0, z0);
                glTexCoord2f(j / (float)longs, (i - 1) / (float)lats);
                glVertex3f(x * zr0, y * zr0, z0);

                glNormal3f(x * zr1, y * zr1, z1);
                glTexCoord2f(j / (float)longs, i / (float)lats);
                glVertex3f(x * zr1, y * zr1, z1);
            }
            glEnd();
        }
    }
    glPopMatrix();

    // Load texture image for torus ring using stb_image
    int torus_width, torus_height, torus_channels;
    unsigned char* torus_texture_data = stbi_load("../rope.png", &torus_width, &torus_height, &torus_channels, STBI_rgb_alpha);

    // Generate texture ID for torus ring texture
    GLuint torus_texture_id;
    glGenTextures(1, &torus_texture_id);

    // Bind texture for torus ring
    glBindTexture(GL_TEXTURE_2D, torus_texture_id);

    // Set texture parameters for torus ring texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    // Load texture data for torus ring texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, torus_width, torus_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, torus_texture_data);

    // Free texture data for torus ring
    stbi_image_free(torus_texture_data);

    // Bind texture before rendering the torus ring
    glBindTexture(GL_TEXTURE_2D, torus_texture_id);

    // Draw torus ring at the top of the sphere
    glPushMatrix();
    glTranslatef(0, -0.25, 1.75);  // translate to the top of the sphere
    glRotatef(90, 0, 1, 0);   // rotate to be parallel with the XY plane

    // Set torus ring parameters
    GLfloat torus_radius = 1;
    GLfloat torus_thickness = 0.15;
    GLint torus_sides = 32;
    GLint torus_rings = 8;

    // Draw torus ring
    GLUquadricObj* quadric = gluNewQuadric();
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluQuadricTexture(quadric, GL_TRUE);
    glPushMatrix();
    glRotatef(90, 0, 1, 90);  // rotate to be perpendicular to the XY plane
    glTranslatef(0.35, 0.15, -torus_thickness / 2);  // translate to center of torus ring
    gluDisk(quadric, torus_radius - torus_thickness, torus_radius, torus_sides, 1);
    gluCylinder(quadric, torus_radius, torus_radius, torus_thickness, torus_sides, torus_rings);
    glTranslatef(0, 0, torus_thickness);  // translate to other end of torus ring
    gluDisk(quadric, torus_radius - torus_thickness, torus_radius, torus_sides, 1);
    glPopMatrix();
    gluDeleteQuadric(quadric);
    glPopMatrix();

    int sprout_width, sprout_height, sprout_channels;
    // Load texture image for sprout using stb_image
    unsigned char* sprout_texture_data = stbi_load("../accent.png", &sprout_width, &sprout_height, &sprout_channels, STBI_rgb_alpha);

    // Generate texture ID for sprout texture
    GLuint sprout_texture_id;
    glGenTextures(1, &sprout_texture_id);

    // Bind texture for sprout
    glBindTexture(GL_TEXTURE_2D, sprout_texture_id);

    // Set texture parameters for sprout texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    // Load texture data for sprout texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sprout_width, sprout_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, sprout_texture_data);

    // Free texture data for sprout
    stbi_image_free(sprout_texture_data);

    // Bind texture before rendering the sprout
    glBindTexture(GL_TEXTURE_2D, sprout_texture_id);

    // Draw cylinder for spout
    glPushMatrix();
    glTranslatef(-0.1, -0.60, 0.55);  // Move the spout to the back side of the sphere
    glRotatef(300, -45, 1, 0);  // Rotate the spout to point towards the back
    gluCylinder(gluNewQuadric(), 0.2, 0.1, 0.45, 16, 16);
    glPopMatrix(); 

    // Load texture image for torus ring using stb_image
    int torus2_width, torus2_height, torus2_channels;
    unsigned char* torus2_texture_data = stbi_load("../accent.png", &torus2_width, &torus2_height, &torus2_channels, STBI_rgb_alpha);

    // Generate texture ID for torus ring texture
    GLuint torus2_texture_id;
    glGenTextures(1, &torus2_texture_id);

    // Bind texture for torus ring
    glBindTexture(GL_TEXTURE_2D, torus2_texture_id);

    // Set texture parameters for torus ring texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    // Load texture data for torus ring texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, torus2_width, torus2_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, torus2_texture_data);

    // Free texture data for torus ring
    stbi_image_free(torus2_texture_data);

    // Bind texture before rendering the torus ring
    glBindTexture(GL_TEXTURE_2D, torus2_texture_id);

    // Draw torus ring at the bottom of the sphere
    glPushMatrix();
    glTranslatef(-0.07, -0.05, -0.40); // translate to the bottom of the sphere
    glRotatef(360, 1, 0, 0); // rotate to be parallel with the XY plane

    // Set torus ring parameters
    GLfloat torus2_radius = 0.95;
    GLfloat torus2_thickness = 0.15;
    GLint torus2_sides = 32;
    GLint torus2_rings = 8;

    // Draw torus ring
    GLUquadricObj* quadric2 = gluNewQuadric();
    gluQuadricNormals(quadric2, GLU_SMOOTH);
    gluQuadricTexture(quadric2, GL_TRUE);
    glPushMatrix();
    glTranslatef(-0.01, 0.15, 0); 
    gluQuadricTexture(quadric2, GL_TRUE);
    gluDisk(quadric2, torus2_radius - torus2_thickness, torus2_radius, torus2_sides, 1);
    gluQuadricTexture(quadric2, GL_FALSE);
    gluCylinder(quadric2, torus2_radius, torus2_radius, torus2_thickness, torus2_sides, torus2_rings);
    glTranslatef(0, 0, torus2_thickness);
    gluQuadricTexture(quadric2, GL_TRUE);
    gluDisk(quadric2, torus2_radius - torus2_thickness, torus2_radius, torus2_sides, 1);
    glPopMatrix();
    gluDeleteQuadric(quadric2);
    glPopMatrix();

    // Disable texturing
    glDisable(GL_TEXTURE_2D);
}

// The function for creating the lid
void renderLid(float x1, float y1, float z1, float x2, float y2, float z2, float radius)
{
    float vx = x2 - x1;
    float vy = y2 - y1;
    float vz = z2 - z1;

    // Calculate length of cylinder
    float length = sqrt(vx * vx + vy * vy + vz * vz);

    // Calculate the rotation angle for the cylinder 
    float angle = acos(vz / length) * 180 / M_PI;

    // Calculate the rotation axis for the cylinder
    float axisX = -vy * vz;
    float axisY = vx * vz;
    float axisZ = 0;

    // Load texture image 
    int width, height, nrChannels;
    unsigned char* data = stbi_load("../disk.png", &width, &height, &nrChannels, 0);
    if (!data) {
        std::cerr << "Failed to load texture" << std::endl;
        exit(EXIT_FAILURE);
    }

    GLuint texture_id;
    glGenTextures(1, &texture_id);

    glBindTexture(GL_TEXTURE_2D, texture_id);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Free image data
    stbi_image_free(data);

    // Bind texture
    glBindTexture(GL_TEXTURE_2D, texture_id);

    // Draw the cylinder
    glPushMatrix();
    glTranslatef(x1, y1, z1);
    glRotatef(angle, axisX, axisY, axisZ);

    glEnable(GL_TEXTURE_2D);
    gluQuadricTexture(gluNewQuadric(), GL_TRUE);
    gluCylinder(gluNewQuadric(), radius, radius, length, 32, 32);
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();

    // Draw the disk on top of the cylinder 
    float center[3] = { x2, y2, z2 };
    float normal[3] = { 0, 0, 1 };
    int num_segments = 32;
    float step = 2 * M_PI / num_segments;
    float angle_rad = 0;
    float radius2 = radius;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_id);

    glBegin(GL_TRIANGLE_FAN);
    glNormal3fv(normal);
    glVertex3fv(center);
    for (int i = 0; i <= num_segments; i++) {
        float x = center[0] + radius2 * cos(angle_rad);
        float y = center[1] + radius2 * sin(angle_rad);
        float z = center[2];
        float u = 0.5 + 0.5 * cos(angle_rad);
        float v = 0.5 + 0.5 * sin(angle_rad);
        glTexCoord2f(u, v);
        glVertex3f(x, y, z);
        angle_rad += step;
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);

    // Draw the sphere on top of the cylinder and disk
    glPushMatrix();
    glTranslatef(x2, y2, z2 + 0.10);
    glRotatef(angle, axisX, axisY, axisZ);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_id);

    gluQuadricTexture(gluNewQuadric(), GL_TRUE);
    gluSphere(gluNewQuadric(), radius / 2.0, 32, 32);

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

int main(void)
{
    GLFWwindow* window;
            
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(1200, 720, "3D Scene: Brandon Petersen", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK)
        return -1;

    // Enable depth testing 
    glEnable(GL_DEPTH_TEST);

    // Setting the viewport
    glViewport(0, 0, 1200, 720);

    // Setting the camera position
    float camX = 2.0f;
    float camY = 0.0f;
    float camZ = 0.0f;

    // Setting the camera movement speed
    float camSpeed = 0.1f;

    // Setting the scaling factor
    float scaleFactor = 0.25f;

    // Setting the mouse speed
    double lastMouseX = 320;
    double lastMouseY = 240;

    // Loop until the user closes the window 
    while (!glfwWindowShouldClose(window))
    {
        // Clearing the color and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Projection matrix
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, 640.0f / 480.0f, 0.1f, 100.0f);

        // Set the spotlight position and orientation 
        GLfloat spotlight_pos[] = { 0.0f, 5.0f, 0.0f, 1.0f };
        GLfloat spotlight_dir[] = { 0.0f, -1.0f, 0.0f };

        // Set the spotlight parameters 
        GLfloat spotlight_cutoff = 50.0f;
        GLfloat spotlight_exponent = 5.0f;
        GLfloat spotlight_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
        GLfloat spotlight_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat spotlight_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat spotlight_attenuation[] = { 1.0f, 0.0f, 0.0f };

        // Set the sphere spotlight position 
        glPushMatrix();
        glTranslatef(-1.0f, 1.0f, 0.0f);

        // Render the sphere spotlight 
        glColor3f(1.0f, 1.0f, 1.0f);
        gluSphere(gluNewQuadric(), 0.1f, 32, 32);

        // Restore the modelview matrix 
        glPopMatrix();

        // Set the spotlight parameters 
        glLightfv(GL_LIGHT1, GL_POSITION, spotlight_pos);
        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotlight_dir);
        glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, spotlight_cutoff);
        glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, spotlight_exponent);
        glLightfv(GL_LIGHT1, GL_AMBIENT, spotlight_ambient);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, spotlight_diffuse);
        glLightfv(GL_LIGHT1, GL_SPECULAR, spotlight_specular);
        glLightfv(GL_LIGHT1, GL_CONSTANT_ATTENUATION, &spotlight_attenuation[0]);
        glLightfv(GL_LIGHT1, GL_LINEAR_ATTENUATION, &spotlight_attenuation[1]);
        glLightfv(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, &spotlight_attenuation[2]);

        // Enable the spotlight 
        glEnable(GL_LIGHT1);

        // Model view matrix
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(camX, camY, camZ, 0, 0, 0, 0, 1, 0);

        // Centering the rendered image
        glTranslatef(0, -0.5, 0);

        // Rotating the disk along the x-axis
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

        // Setting the scaling factor
        glScalef(scaleFactor, scaleFactor, scaleFactor);

        // Rendering the first cylinder which represents the first teacup
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        renderCylinder(1.10, -1, 0, 0, 1, 0, 0.5, "../testcup.png");

        // Rendering the second cylinder which represents second teacup
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        renderCylinderTwo(1.5, 0.50, 0, 0, 1, 0, 0.5, "../testcup.png");

        // Rendering the third cylinder which represents cup with lid
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        renderCylinderThree(-0.25, 0.95, 0, -0.25, 0.95, 2.25, 0.60, "../cup2.png");

        // Rendering the disk which represents the serving tray with texture
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        renderDisk(0, 0, 0, 0, 2.5, "../disk.png");

        // Rendering the sphere which represents the teapot with texture
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glPushMatrix();
        glTranslatef(-(1 + 0.25 + 0.05), -0.7, 0.40);
        glScalef(-1, 1, 1);
        renderSphere();
        glPopMatrix();

        // Rendering the teapot lid
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        renderLid(-1.3, -0.70, 1.65, -1.3, -0.70, 2.40, 0.20);

        // Swaping the front and back buffers
        glfwSwapBuffers(window);

        // Poll for and handle events
        glfwPollEvents();

        // Adding camera movement with keyboard
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, true);
        }

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            camX -= camSpeed;
        }

        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            camX += camSpeed;
        }

        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            camZ += camSpeed;
        }

        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            camZ -= camSpeed;
        }

        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        {
            camY += camSpeed;
        }

        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        {
            camY -= camSpeed;
        }

        // Adding camera movement with mouse
        double mouseX, mouseY;
        glfwGetCursorPos(window, &mouseX, &mouseY);

        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
        {
            double deltaX = mouseX - lastMouseX;
            double deltaY = mouseY - lastMouseY;

            camX += deltaX * 0.005f;
            camY -= deltaY * 0.005f;
        }

        lastMouseX = mouseX;
        lastMouseY = mouseY;
    }

    glfwTerminate();
    return 0;
}