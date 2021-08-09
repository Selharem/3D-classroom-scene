#include "window.h"

void Window :: drawWindow1(){
//fenetre 1
glColor3f(0.6f, 0.7333f, 1.0f);
glBegin(GL_QUADS);
glVertex3f(-9.99f, 2.0f, 6.0f);
glVertex3f(-9.99f, 5.0f, 6.0f);
glVertex3f(-9.99f, 5.0f, 2.0f);
glVertex3f(-9.99f, 2.0f, 2.0f);
glEnd();

glColor3f(0.149f, 0.149f, 0.149f);
glLineWidth(10.0f);
glBegin(GL_LINES);
//gauche
glVertex3f(-9.98f, 2.0f, 6.0f);
glVertex3f(-9.98f, 5.0f, 6.0f);
//haut
glVertex3f(-9.98f, 5.0f, 6.0f);
glVertex3f(-9.98f, 5.0f, 2.0f);
//droite
glVertex3f(-9.98f, 2.0f, 2.0f);
glVertex3f(-9.98f, 5.0f, 2.0f);
//bas
glVertex3f(-9.98f, 2.0f, 6.0f);
glVertex3f(-9.98f, 2.0f, 2.0f);
glEnd();

//Travers
glLineWidth(3.0f);
glBegin(GL_LINES);
glVertex3f(-9.98f, 2.0f, 4.0f);
glVertex3f(-9.98f, 5.0f, 4.0f);

glVertex3f(-9.98f, 3.5f, 6.0f);
glVertex3f(-9.98f, 3.5f, 2.0f);
glEnd();
}

void Window :: drawWindow2(){
//fenetre 2
glColor3f(0.6f, 0.7333f, 1.0f);
glBegin(GL_QUADS);
glVertex3f(-9.99f, 2.0f, -6.0f);
glVertex3f(-9.99f, 5.0f, -6.0f);
glVertex3f(-9.99f, 5.0f, -2.0f);
glVertex3f(-9.99f, 2.0f, -2.0f);
glEnd();

glColor3f(0.149f, 0.149f, 0.149f);
glLineWidth(10.0f);
glBegin(GL_LINES);
//gauche
glVertex3f(-9.98f, 2.0f, -6.0f);
glVertex3f(-9.98f, 5.0f, -6.0f);
//haut
glVertex3f(-9.98f, 5.0f, -6.0f);
glVertex3f(-9.98f, 5.0f, -2.0f);
//droite
glVertex3f(-9.98f, 2.0f, -2.0f);
glVertex3f(-9.98f, 5.0f, -2.0f);
//bas
glVertex3f(-9.98f, 2.0f, -6.0f);
glVertex3f(-9.98f, 2.0f, -2.0f);
glEnd();

//Travers
glLineWidth(3.0f);
glBegin(GL_LINES);
glVertex3f(-9.98f, 2.0f, -4.0f);
glVertex3f(-9.98f, 5.0f, -4.0f);

glVertex3f(-9.98f, 3.5f, -6.0f);
glVertex3f(-9.98f, 3.5f, -2.0f);
glEnd();
}

void Window :: drawWindowSill(){
glColor3f(0.149f, 0.149f, 0.149f);
glBegin(GL_QUADS);
glVertex3f(-9.99f, 2.0f, -6.0f);
glVertex3f(-9.99f, 2.0f, -2.0f);
glVertex3f(-9.5f, 2.0f, -2.0f);
glVertex3f(-9.5f, 2.0f, -6.0f);

glColor3f(0.2f, 0.2f, 0.2f);
glVertex3f(-9.5f, 2.0f, -6.0f);
glVertex3f(-9.5f, 2.0f, -2.0f);
glVertex3f(-9.5f, 1.8f, -2.0f);
glVertex3f(-9.5f, 1.8f, -6.0f);

glColor3f(0.24f, 0.24f, 0.24f);
glVertex3f(-9.99f, 2.0f, -6.0f);
glVertex3f(-9.5f, 2.0f, -6.0f);
glVertex3f(-9.5f, 1.8f, -6.0f);
glVertex3f(-9.99f, 1.8f, -6.0f);

glVertex3f(-9.99f, 2.0f, -2.0f);
glVertex3f(-9.5f, 2.0f, -2.0f);
glVertex3f(-9.5f, 1.8f, -2.0f);
glVertex3f(-9.99f, 1.8f, -2.0f);

glEnd();
}


