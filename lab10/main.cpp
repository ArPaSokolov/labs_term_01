#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include "Figures.h"

int main()
{
    // задаем окно
    int Width = 1000;
    int Height = 600;
    sf::RenderWindow window(sf::VideoMode(Width, Height), "10_lab works!");

    myclass::Figures Rect;
    // задаем прямоугольник
    Rect.SetRect(9999, -9999, 400, 600, sf::Color::Blue, 100, 100); // скорость, позииця, цвет, стороны
    sf::RectangleShape rectangle{ { Rect.A * 1.0f, Rect.B * 1.0f } };
    rectangle.setPosition({ Rect.x0 * 1.0f, Rect.y0 * 1.0f });
    rectangle.setFillColor(Rect.color);

    myclass::Figures Circle;
    // задаем круг
    Circle.SetCircle(2600, -99, 500, 400, sf::Color::Red, 50); // скорость, позииця, цвет, стороны 
    sf::CircleShape shape(Circle.R * 1.0f);
    shape.setPosition({ Circle.x0 * 1.0f, Circle.y0 * 1.0f });
    shape.setFillColor(Circle.color);

    //Rect.SetRect(333, -1000, 100, 600, sf::Color::Blue, 100, 100); // скорость, позииця, цвет, стороны
    //Circle.SetCircle(140, -3000, 200, 500, sf::Color::Red, 50); // скорость, позииця, цвет, стороны


    
    /*------------------------------------------------------------------запускаем программу----------------------------------------------------*/
    
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Green);

        // определяем положение фигур
        Rect.SetCoords(Width);
        Circle.SetCoords(Width);
        
        /*----------------------------------------------------------перемещаем прямоугольник--------------------------------------------------*/
        Rect.RectFlag(Width, Height);
        if (Rect.flag == 0)
        {
            Rect.x0 += Rect.v_x;
            Rect.y0 += Rect.v_y;
            rectangle.setPosition({ (Rect.x0) * 1.0f, (Rect.y0) * 1.0f });
        }
        // воткнулся вправо
        if (Rect.flag == 1)
        {

            Rect.h = (abs(Rect.v_y) * (Rect.xn - Width - Rect.B)) / (abs(Rect.v_x));
            rectangle.setPosition({ (Width - Rect.B) * 1.0f, (Rect.yn + Rect.h) * 1.0f });
        }

        // воткнулся в угол
        if (Rect.flag == 2)
        {
            Rect.w = (abs(Rect.v_x) * Rect.y0)/(abs(Rect.v_y));
            rectangle.setPosition({ (Rect.x0 + Rect.w) * 1.0f, 0 * 1.0f });
        }
        if (Rect.flag == 3)
        {
            rectangle.setPosition({ (Width - Rect.B) * 1.0f, 0 * 1.0f });
        }





        /*----------------------------------------------------------перемещаем круг----------------------------------------------------------*/

        Circle.CircleFlag(Width, Height);
        if (Circle.flag == 0)
        {
            Circle.x0 += Circle.v_x;
            Circle.y0 += Circle.v_y;
            shape.setPosition({ (Circle.x0) * 1.0f, (Circle.y0) * 1.0f });
        }
        if (Circle.flag == 1)
        {
            Circle.h = (abs(Circle.v_y) * (Circle.xn - Width - 2 * Circle.R)) / (abs(Circle.v_x));
            shape.setPosition({ (Width - 2 * Circle.R) * 1.0f, (Circle.yn + Circle.h) * 1.0f });
        }
        if (Circle.flag == 2)
        {
            Circle.w = (abs(Circle.v_x) * Circle.y0) / (abs(Circle.v_y));
            shape.setPosition({ (Circle.x0 + Circle.w) * 1.0f, 0 * 1.0f });
        }
        if (Circle.flag == 3)
        {
            shape.setPosition({ (Width - 2 * Circle.R) * 1.0f, 0 * 1.0f });
        }


        /*----------------------------------------------------------отрисовываем-------------------------------------------------------------*/

        window.draw(rectangle);
        window.draw(shape);
        window.display();

        // задержка
        /*std::this_thread::sleep_for(std::chrono::milliseconds(100));*/
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    return 0; 
}