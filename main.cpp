#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include "interface.h"
#include "rect.h"
#include "bouton.h"
#include "menu.h"
#include "Tf.h"
#include "gestaff.h"
#include <allegro.h>
using namespace std;

BITMAP*page;


int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    /*point p(10,20);
    p.affiche();
    rectangle r1;
    r1.affiche();
    rectangle r2(100,100,20,10,3,4);
    r2.affiche();
    */

    /*
    bouton b1;
    b1.affiche();
    bouton b2(10,20,"iut");
    b2.affiche();
    bouton b3(b2);
    b3.affiche();
    bouton b4 = b3;
    b4.affiche();
    */

    allegro_init();
    install_keyboard();   //installe le clavier
    install_mouse();      //installe la souris
    set_color_depth(32);        //theme couleur sur 32 bits

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0)!=0)       // sélectionner un driver graphique approprié +initialisation de la résolution de l'écran (tailles 640-480)
    {
        allegro_message(allegro_error);
      	allegro_exit();
      	return 1;
   	}

    set_mouse_sprite(NULL);      //format de la souris
    show_mouse(screen);
    set_keyboard_rate(0,0);

    page = create_bitmap(SCREEN_W,SCREEN_H);    //initialisation du buffer page

    const char* tmp[]={"rectangle","cercle","effacer","quitter"};
    menu m(tmp,4);
    m.affiche();
    blit(page,screen,0,0,0,0,page->w,page->h);

    gestaff* aff = new gestaff;
    Tf *ptn;
    ptn = new point(10,10);
    aff->ajoute(ptn);
    ptn = new rectangle(10,20,30,40);
    aff->ajoute(ptn);
    ptn = new bouton;
    aff->ajoute(ptn);

    int fin = 1;
    do
    {
        clear_bitmap(page);
        m.affiche();
        int choix = m.selection();
        switch(choix)
        {
            case 1 :
                {
                    rectfill(page,400,100,500,200,makecol(255,255,255));
                    break;
                }
            case 2 :
                {
                    circlefill(page,500,400,60,makecol(128,128,128));
                    break;
                }
            case 3 :
                {
                    //clear_bitmap(page);                           //inutile dans ce cas
                    //m.affiche();
                    //blit(page,screen,0,0,0,0,page->w,page->h);
                    break;
                }
            case 4 :
                {
                    fin = 0;
                    break;
                }
        }
        aff->affiche();
        blit(page,screen,0,0,0,0,page->w,page->h);
    }while(fin);

    textprintf_ex(screen,font,200,400,makecol(255,0,0),-1,"appuyer sur espace pour quitter");

    readkey();	// fct équivalente à getch() de conio.c
    set_gfx_mode(GFX_TEXT,0,0,0,0);

    destroy_bitmap(page);

    exit(EXIT_SUCCESS) ;
}END_OF_MAIN() ;
