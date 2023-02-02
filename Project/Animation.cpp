#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include "AnimationClass.h"

int main()
{
    /*--------------------------------------------задаем окно------------------------------------------------------*/
    int Width = 1150;
    int Height = 600;
    sf::RenderWindow window(sf::VideoMode(Width, Height), "Evil magician!");

    sf::Texture backgroundTexture; //создаем текстуру для фона
    backgroundTexture.loadFromFile("images/background.jpg"); //передаем текстуре фона изображение

    sf::Sprite background; //создаем спрайт для фона
    background.setTexture(backgroundTexture); //надеваем текстуру фона на спрайт


    /*------------------------------------------задаем героя-------------------------------------------------------*/
    Animation hero;

    hero.SetHero(Width - 250, Height - 370, 150, 237); //x0, y0, RectW, RectH 

    sf::Texture heroTexture; //создаем текстуру для героя
    heroTexture.loadFromFile("images/hero.png"); //передаем текстуре героя изображение

    sf::Sprite heroSprite; //создаем спрайт для героя
    heroSprite.setTexture(heroTexture); //передаём спрайту героя текстуру
    heroSprite.setPosition(hero.GetX0(), hero.GetY0()); //задаем координаты появления спрайта героя


    /*---------------------------------------задаем файербол-------------------------------------------------------*/
    Animation fireball;

    fireball.SetFireball(hero.GetX0() + 10, hero.GetY0() + 50, 76, 76, -70, 0);//x0, y0, FireballW, FireballH, v_x, v_y

    sf::Texture fireballTexture;//создаем текстуру для файербола
    fireballTexture.loadFromFile("images/fireball.png");;//передаем текстуре файербола изображение

    sf::Sprite fireballSprite;//создаем спрайт для файербола
    fireballSprite.setTexture(fireballTexture);//передаём спрайту файербола текстуру
    

    /*--------------------------------------запускаем программу-----------------------------------------------------*/
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
        window.draw(background); //выводим спрайт на экран
        
        
        /*-----------------------------------анимация героя--------------------------------------------------------*/
        hero.SetHeroAnimation(); //определяем какой тайл нужно взять

        // передаем спрайту текстуру тайла героя
        heroSprite.setTextureRect(sf::IntRect(hero.GetRectW() * hero.GetPose(), 0, hero.GetRectW(), hero.GetRectH())); //(откуда по X, откуда по Y, сколько по X, сколько по Y)

        window.draw(heroSprite);//выводим спрайт на экран


        /*---------------------------------анимация файербола------------------------------------------------------*/
        fireball.SetLaunch(hero.GetLaunch()); //передаем файерболу нужно ли ему лететь
        if (fireball.GetLaunch() == true) //если нужно
        {
            fireball.SetX0(fireball.GetX0() + fireball.GetVX()); //задаем координату х0
            fireball.SetY0(fireball.GetY0() + hero.GetVY()); //задаем координату у0
            fireballSprite.setPosition(fireball.GetX0(), fireball.GetY0()); //определяем положение
            window.draw(fireballSprite); //выводим спрайт файербола на экран
        }
        if (fireball.GetX0() < 0) //если файербол вылетел за границы экрана (х0 < 0)
        {
            fireball.SetX0(hero.GetX0() + 20); //возвращаем начальную позицию по Х
            fireball.SetY0(hero.GetY0() + 100); //возвращаем начальную позицию по Y
            hero.SetLaunch(false); //файерболу запускаться не нужно
        }
  
        window.display();
        window.clear();

        // задержка
        /*std::this_thread::sleep_for(std::chrono::seconds(1));*/
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    return 0; 
}