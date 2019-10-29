#include <SFML/Graphics.hpp>///use it for graphics
#include <SFML/Audio.hpp>///use it for sound and music
#include<sstream>
#include<iostream>
#include<windows.h>
using namespace sf;
using namespace std;


string sss(double n);

int main()
{
    srand(time(NULL));///for random number
    float carpos,ecar1pos,ecar2pos,ecar3pos;
    double score = 0;
    int x=0;
    int speed = 300,i=0,j=0,k=0,randm=1,xx=0;
    randm = rand()% 6+1;
    RenderWindow window(VideoMode(800,800),"car racing game");///creat window
n:
    speed = 300;
    while(window.isOpen())///open window for start menu
    {
        Texture st;
        st.loadFromFile("frontepage.png");
        Sprite start(st);
        window.clear();
        window.draw(start);     ///open photo from pc
        window.display();
        Event b;
        while(window.pollEvent(b))
        {
            if(b.type == Event::Closed)
                window.close();
            if(b.type==Event::KeyPressed)
            {
                if(b.key.code==Keyboard::Enter)
                    goto a;///for enter exit for game
                if(b.key.code==Keyboard::Escape)
               window.close();
            }

        }
    }
a:
    Music music;///open music for car racing/
    if(!music.openFromFile("carsound.ogg"))
    {
        printf("Error");
    }
    SoundBuffer buffer;
    if(!buffer.loadFromFile("s.ogg"))
    {
        printf("Error");
    }
    sf :: RectangleShape road(sf::Vector2f(400.0f,800.0f));
     sf :: RectangleShape car(sf::Vector2f(60.0f,100.0f));
     sf :: RectangleShape ecar1(sf::Vector2f(50.0f,100.0f));
     sf :: RectangleShape ecar2(sf::Vector2f(50.0f,100.0f));
     sf :: RectangleShape ecar3(sf::Vector2f(50.0f,100.0f));
     sf :: Texture roadTexture;
     sf :: Texture carTexture;
     sf :: Texture ecar1Texture;
     sf :: Texture ecar2Texture;
     sf :: Texture ecar3Texture;
     if(!roadTexture.loadFromFile("road.jpg"))
    cout<<"Could not load the image fill"<<endl;
        road.setTexture(&roadTexture);
     if(!carTexture.loadFromFile("car.png"))
    cout<<"Could not load the image fill"<<endl;
        car.setTexture(&carTexture);
        if(!ecar1Texture.loadFromFile("ecar.png"))
    cout<<"Could not load the image fill"<<endl;
        ecar1.setTexture(&ecar1Texture);
        if(!ecar2Texture.loadFromFile("ecar.png"))
    cout<<"Could not load the image fill"<<endl;
        ecar2.setTexture(&ecar2Texture);
        if(!ecar3Texture.loadFromFile("ecar.png"))
    cout<<"Could not load the image fill"<<endl;
        ecar3.setTexture(&ecar3Texture);
    /*Texture p1;
    Texture p2;
    Texture p3;*/
    Texture p4;
   /* p1.loadFromFile("road.jpg");
    p2.loadFromFile("car.png");
    p3.loadFromFile("ecar.png");*/
    p4.loadFromFile("boom.png");
    ///Sprite road(p1);
    ///Sprite car(p2);
    ///Sprite ecar1(p3);
    ///Sprite ecar2(p3);
    /// Sprite ecar3(p3);*/
    Sprite boom(p4);
    ///Sprite road(p1);
    ////////////////
    car.move(170,700);
    ecar1.move(20,-100);      ///to set position for cars
    ecar2.move(170,-100);
    ecar3.move(320,-100);
    boom.move(0,500);
    /////
    Font myfont;
    Text myscore;
    Text text1;
    Text text2;
    Text text3;
    Text text4;
    Text text5;
    Text text6;
    /////
    if(!myfont.loadFromFile("shakil.ttf"))///to add text
        printf("Error");
    music.play();///to play car sound
    music.setLoop(true);///to repeat car sound
    while(window.isOpen())///to open window
    {
        ///score
        myscore.setFont(myfont);
        myscore.setString(sss(score));
        myscore.setCharacterSize(30);
        myscore.setColor(Color(255,0,0));
        myscore.setPosition(520,40);
        score += 0.01; ///this score will change to string
        ////////
        text1.setFont(myfont);
        text1.setString("CAR RACING");///write text to print it
        text1.setCharacterSize(30);///text size
        text1.setColor(Color(255,0,0));///text color
        text1.setPosition(400,0);///text position

        //////
        text2.setFont(myfont);
        text2.setString("SCORE");///write text to print it
        text2.setCharacterSize(30);///text size
        text2.setColor(Color(255,0,0));///text color
        text2.setPosition(400,40);
        ///////
        ///////
        text3.setFont(myfont);
        text3.setString("SHAKIL");///write text to print it
        text3.setCharacterSize(40);///text size
        text3.setColor(Color(255,0,0));///text color
        text3.setPosition(400,80);///text position
        ///
        text4.setFont(myfont);
        text4.setString("2018831072");///write text to print it
        text4.setCharacterSize(40);///text size
        text4.setColor(Color(255,0,0));///text color
        text4.setPosition(400,120);///text position
       //////////////
       text5.setFont(myfont);
        text5.setString("FAHIM");///write text to print it
        text5.setCharacterSize(40);///text size
        text5.setColor(Color(255,0,0));///text color
        text5.setPosition(400,160);///text position
       //////////////
       text6.setFont(myfont);
        text6.setString("2018831064");///write text to print it
        text6.setCharacterSize(40);///text size
        text6.setColor(Color(255,0,0));///text color
        text6.setPosition(400,200);///text position
       //////////////
        carpos = car.getPosition().x;///taking coordinates x for car
        ///carpos = car.getPosition().y;///taking coordinates y for car
        ecar1pos = ecar1.getPosition().y; ///taking coordinates y for car
        ecar2pos = ecar2.getPosition().y;
        ecar3pos = ecar3.getPosition().y;
        /////

        if(carpos>=20&&carpos<=100&&ecar1pos>=600)///condition of loss of the game
        {
            car.setPosition(20,700);
            window.clear();
            window.draw(road);
            window.draw(car);
            window.draw(ecar1);
            window.draw(ecar2);    ///to display photo
            window.draw(ecar3);
            window.draw(myscore);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);
            window.draw(text4);
            window.draw(text5);
            window.draw(text6);
            window.display();

            //////
            music.pause();
            Sound sound;
            sound.setBuffer(buffer);///car sound
            sound.play();

            window.draw(boom);
            window.display();
            Sleep(300);
            goto n;

        }
        if(carpos>=50&&carpos<=250&&ecar2pos>=600)///condition of loss of the game
        {
            car.setPosition(170,700);
            window.clear();
            window.draw(road);
            window.draw(car);
            window.draw(ecar1);
            window.draw(ecar2);    ///to display photo
            window.draw(ecar3);
            window.draw(myscore);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);
            window.draw(text4);
            window.draw(text5);
            window.draw(text6);
            window.display();

            //////
            music.pause();
            Sound sound;
            sound.setBuffer(buffer);///car sound
            sound.play();

            window.draw(boom);
            window.display();
            Sleep(300);
            goto n;

        }
        if(carpos>=200&&carpos<=320&&ecar3pos>=600)///condition of loss of the game
        {
            car.setPosition(320,700);
            window.clear();
            window.draw(road);
            window.draw(car);
            window.draw(ecar1);
            window.draw(ecar2);    ///to display photo
            window.draw(ecar3);
            window.draw(myscore);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);
            window.draw(text4);
            window.draw(text5);
            window.draw(text6);
            window.display();

            //////
            music.pause();
            Sound sound;
            sound.setBuffer(buffer);///car sound
            sound.play();

            window.draw(boom);
            window.display();
            Sleep(300);
            goto n;

        }
        ////////
        if(i==799||j==799 || k==799)
            randm = rand()%6+1;   ///to get randomcar to make random car
        x=0;
        //////////////////////
        if(randm==1)
        {
            ecar1.move(0,1);
        }
        if(randm==2)
        {
            ecar2.move(0,1);
        }
        if(randm==3)
        {
            ecar3.move(0,1);
        }
        if(randm==4)
        {
            ecar1.move(0,1.5);
            ecar2.move(0,1);
        }
        if(randm==5)
        {
            ecar1.move(0,1);
            ecar3.move(0,1.5);
        }
        if(randm==6)
        {
            ecar2.move(0,1.5);
            ecar3.move(0,1);
        }
        ///////
        if(i == 800)
        {
            if(speed<=700)
                speed +=3;

            i=0;
            ecar1.setPosition(20,-100);    ///to enter car in loop
        }
        if(j == 800)
        {
            if(speed<=700)
                speed +=1;

            j=0;
            ecar2.setPosition(170,-100);
        }
        if(k == 800)
        {
            if(speed<=700)
                speed +=3;

            k=0;
            ecar3.setPosition(320,-100);    ///to enter car in loop
        }

        i++,j++,k++;
//////////////////////////////////////////
        window.setFramerateLimit(speed);
        Event e;
        while(window.pollEvent(e))///to open window
        {
            if(e.type == Event :: Closed)
                window.close();
            if(e.type==Event::KeyPressed)
            {
                if(e.key.code==Keyboard::Left && xx>=-100)///if press left ,move car to left
                {
                    x=x-150;
                    xx=xx-150;
                }
                if(e.key.code==Keyboard::Right && xx<=100)///if press  right ,move car to right
                {
                    x=x+150;
                    xx=xx+150;
                }
                car.move(x,0);
            }
        }
        window.clear();
        window.draw(road);
        window.draw(car);
        window.draw(ecar1);
        window.draw(ecar2);    ///to display photo
        window.draw(ecar3);
        window.draw(myscore);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(text5);
        window.draw(text6);
        window.display();

    }
    return 0;
}
 string sss(double n) ///this function to change number to string and use it for score
{
    stringstream ss;
    ss<<n;
    return ss.str();
}
