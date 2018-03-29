/**
 * @author Reid Rumack
 * @file   main.cpp
 * @date   3/23/2018
 * @project lab 3
 *
 * Tests the GraphicsContext class.
 */
#include "x11context.h"
#include <unistd.h>
#include <iostream>
#include <cmath>
 
int main(void)
{
	GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);

	gc->setColor(GraphicsContext::GREEN);
    // draw some lines bow & arrow target
    for (int i = 0; i < 5; ++i) {
        gc->setColor(GraphicsContext::WHITE);

        gc->drawCircle(300, 300, (200 / 5) * i);
        if (i == 0) {
            gc->setColor(GraphicsContext::YELLOW);
            for (int j = 0; j < (200 / 5); ++j) {
                gc->drawCircle(300, 300, j);
            }
        } else if (i == 1) {
            gc->setColor(GraphicsContext::RED);

            for (int j = 0; j < (200 / 5); ++j) {
                gc->drawCircle(300, 300, ((200 / 5)*i)+j);
            }
        } else if (i == 2) {
            gc->setColor(GraphicsContext::CYAN);
            for (int j = 0; j < (200 / 5); ++j) {
                gc->drawCircle(300, 300, ((200 / 5)*i)+j);
            }
        } else if (i == 4) {
            gc->setColor(GraphicsContext::WHITE);
            for (int j = 0; j < (200/5) ; ++j) {
                gc->drawCircle(300, 300, ((200 / 5)*i)+j);
            }
        }
    }
    gc->setColor(GraphicsContext::BLUE);
	sleep(3);
    gc->clear();
    // draws sold square using lines
        for (int k = 0; k <= 180; k += 1) {
            gc->setColor(GraphicsContext::BLUE-k);
            gc->drawLine(300, 300, 480, 300 + k);
            gc->setColor(GraphicsContext::GREEN-(k<<8));
            gc->drawLine(300, 300, 300 + k, 480);
            gc->setColor(GraphicsContext::RED-(k<<16));
            gc->drawLine(300, 300, 480, 300 - k);
            gc->setColor(GraphicsContext::YELLOW-k);
            gc->drawLine(300, 300, 300 - k, 480);
            gc->setColor(GraphicsContext::MAGENTA);
            gc->drawLine(300, 300, 120, 300 + k);
            gc->setColor(GraphicsContext::CYAN);
            gc->drawLine(300, 300, 300 + k, 120);
            gc->setColor(GraphicsContext::GRAY);
            gc->drawLine(300, 300, 120, 300 - k);
            gc->setColor(GraphicsContext::WHITE);
            gc->drawLine(300, 300, 300 - k, 120);

        }
    sleep(5);
	delete gc;
 
	return 0;
}
