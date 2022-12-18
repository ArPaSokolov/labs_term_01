#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include "Figures.h"

int main()
{
    // задаем окно
    int Width = 1150;
    int Height = 600;
    sf::RenderWindow window(sf::VideoMode(Width, Height), "Evil magician!");

    sf::Texture backgroundImage;
    backgroundImage.loadFromFile("images/background.jpg");
    sf::Sprite background(backgroundImage);

    // колдун 
    myclass::Figures hero;

    hero.SetHero(Width - 250, Height - 370, 150, 237);//x0, y0, RectW, RectH 

    sf::Image heroimage; //создаем объект Image (изображение)
    heroimage.loadFromFile("images/hero.png");//загружаем в него файл

    sf::Texture herotexture;//создаем объект Texture (текстура)
    herotexture.loadFromImage(heroimage);//передаем в него объект Image (изображения)

    sf::Sprite herosprite;//создаем объект Sprite(спрайт)
    herosprite.setTexture(herotexture);//передаём в него объект Texture (текстуры)
    herosprite.setPosition(hero.GetX0(), hero.GetY0());//задаем начальные координаты появления спрайта

    // файербол
    myclass::Figures fireball;

    fireball.SetFireball(hero.GetX0()+10, hero.GetY0()+50, 76, 76, -70, 0);//x0, y0, FireballW, FireballH, v_x, v_y

    sf::Image fireballimage; //создаем объект Image (изображение)
    fireballimage.loadFromFile("images/fireball.png");//загружаем в него файл

    sf::Texture fireballtexture;//создаем объект Texture (текстура)
    fireballtexture.loadFromImage(fireballimage);//передаем в него объект Image (изображения)

    sf::Sprite fireballsprite;//создаем объект Sprite(спрайт)
    fireballsprite.setTexture(fireballtexture);//передаём в него объект Texture (текстуры)
    
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
        window.draw(background);//выводим спрайт на экран
        
        
        /*----------------------------------------------------------анимация колдуна-----------------------------------------------------------*/

        hero.SetHeroAnimation();
        herosprite.setTextureRect(sf::IntRect(hero.GetRectW() * hero.GetPose(), 0, hero.GetRectW(), hero.GetRectH())); // откуда по X, откуда по Y, сколько по X, сколько по Y
        window.draw(herosprite);//выводим спрайт на экран
        /*----------------------------------------------------------анимация файербола---------------------------------------------------------*/

        fireball.SetLaunch(hero.GetLaunch());
        if (fireball.GetLaunch() == true)
        {
            fireball.SetX0(fireball.GetX0() + fireball.GetVX()) ;
            fireball.SetY0(fireball.GetY0() + hero.GetVY()); //+ (rand() % 50 - 20)
            fireballsprite.setPosition(fireball.GetX0(), fireball.GetY0());
            window.draw(fireballsprite);//выводим спрайт на экран
        }
        if (fireball.GetX0() < 0)
        {
            fireball.SetX0(hero.GetX0() + 20);
            fireball.SetY0(hero.GetY0() + 100);
            fireball.SetLaunch(false);
            hero.SetLaunch(false);
        }
  
        window.display();
        window.clear();

        // задержка
        /*std::this_thread::sleep_for(std::chrono::seconds(1));*/
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    return 0; 
}