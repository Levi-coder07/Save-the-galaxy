#include "Game.h"
#include "MainMenu.h"
using namespace sf;

int main()
{

    // Make a main window
    RenderWindow MENU(VideoMode(800, 600), "Main Menu", Style::Default);
    MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

    // --------------------------------------------------------------------------------- //
    //set background
    RectangleShape background;
    background.setSize(Vector2f(800, 600));
    Texture Maintexture;
    Maintexture.loadFromFile("Textures/save the galaxy.jpeg");
    background.setTexture(&Maintexture);

   
    //photo to option
    RectangleShape Obackground;
    Obackground.setSize(Vector2f(800, 600));
    Texture Optiontexture;
    Optiontexture.loadFromFile("Textures/galaxia.jpg");
    Obackground.setTexture(&Optiontexture);

    // --------------------------------------------------------------------------------- //


    while (MENU.isOpen())
    {
        Event event;
        while (MENU.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                MENU.close();
            }

            if (event.type == Event::KeyReleased)
            {
                if (event.key.code == Keyboard::W)
                {
                    mainMenu.MoveUp();
                    break;
                }
                if (event.key.code == Keyboard::S)
                {
                    mainMenu.MoveDown();
                    break;
                }
                if (event.key.code == Keyboard::Return) {
                    RenderWindow OPTIONS(VideoMode(800, 600), "OPTIONS");
                    RenderWindow ABOUT(VideoMode(800, 600), "ABOUT");

                    int x = mainMenu.MainMenuPressed();
                    if (x == 0)
                    {            
                        //Initialize game object
                        Game game;

                        game.run();
                        OPTIONS.close();
                        ABOUT.close();
                        game.update(); 
                        game.render(); 
                        

                    }
                    if (x == 1)
                    {

                        while (OPTIONS.isOpen())
                        {
                            Event aevent;
                            while (OPTIONS.pollEvent(aevent)) {
                                if (aevent.type == Event::Closed)
                                {
                                    OPTIONS.close();
                                }
                                if (aevent.type == Event::KeyPressed)
                                {
                                    if (aevent.key.code == Keyboard::Escape)
                                    {
                                        OPTIONS.close();
                                    }
                                }
                            }
         
                            OPTIONS.clear();

                            // ------------------------------------------------- //
                            OPTIONS.draw(Obackground);
                            // ------------------------------------------------- //


                            ABOUT.close();
                            OPTIONS.display();

                        }
                    }
                    if (x == 2)
                    {
                        while (ABOUT.isOpen())
                        {
                            Event aevent;
                            while (ABOUT.pollEvent(aevent)) {
                                if (aevent.type == Event::Closed)
                                {
                                    ABOUT.close();
                                }
                                if (aevent.type == Event::KeyPressed) {
                                    if (aevent.key.code == Keyboard::Escape) {
                                        ABOUT.close();
                                    }
                                }
                            }
                      
                            ABOUT.clear();
                            // ------------------------------------------------- //
                            ABOUT.draw(Obackground);
                            // ------------------------------------------------- //

                   
                            OPTIONS.close();
                            ABOUT.display();
                        }
                    }
                    if (x == 3)
                        MENU.close();
                    break;
                }
            }
        }
        MENU.clear();
  
        MENU.draw(background);
        mainMenu.draw(MENU);
        MENU.display();
    }

    return 0;
}