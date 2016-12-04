#include "Game.hpp"
#define WHITE makecol(255, 255, 255)

//----------------------------------------CTOR-&-DTOR----------------------------------------//

Game::Game(Console* ecran,Graphic* graph)
: m_ecran(ecran),m_Graphic(graph),m_displayMod(0)
{
    //ctor
}

Game::~Game()
{
    //dtor
}

//-------------------------------------SETTERS-&-GETTERS-------------------------------------//

unsigned int Game::GetdisplayMod()
{
    return m_displayMod;
}
void Game::SetdisplayMod(unsigned int val)
{
    m_displayMod = val;
}

//------------------------------------------METHODS------------------------------------------//

void Game::win_display(int winner)
{
    if(GetdisplayMod())
    {

    }
    else
    {
        m_ecran->setColor(COLOR_GREEN);
        // m_ecran->gotoligcol(milieu_x-taille_msg/2, milieu_y);
        std::cout<< (winner==3 ? "Les rhinoceros": "Les elephants") << " gagnent !" << std::endl;
    }
}
void Game::start()
{

     BITMAP* buffer=m_Graphic->Getbuff();
     if(GetdisplayMod())
     {
        set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1000, 600,0,0);
        buffer=create_bitmap(SCREEN_W,SCREEN_H);
     }

    Player rhino(1);
    Player elephant(2);
    if(!GetdisplayMod())
    {
        m_BG.boardCons(m_ecran);
        m_BG.stockCons(m_ecran,MARGINBOARDX-3,MARGINBOARDY);
        m_BG.stockCons(m_ecran,MARGINBOARDX+2*NTAILLE*MULTIPLICATOR+NTAILLE+1,MARGINBOARDY);
        m_BG.stockDispCons(m_ecran,MARGINBOARDX+2*NTAILLE*MULTIPLICATOR+NTAILLE+1,MARGINBOARDY,RHINOCEROS,rhino.GetstockPiece());
        m_BG.stockDispCons(m_ecran,MARGINBOARDX-3,MARGINBOARDY,ELEPHANT,elephant.GetstockPiece());
        m_BG.display(NULL,0,m_ecran);
    }



    int win=0;

    while(!win) //BOUCLE DE JEU
    {
        win=elephant.Play(GetdisplayMod() ,m_BG, m_ecran);
        if(!GetdisplayMod()) m_BG.stockDispCons(m_ecran ,MARGINBOARDX-3,MARGINBOARDY,ELEPHANT,elephant.GetstockPiece());

        if(win==3 || win==4) return win_display(win);
        else
            {win=rhino.Play(GetdisplayMod() ,m_BG, m_ecran);
                if(!GetdisplayMod()) m_BG.stockDispCons(m_ecran,MARGINBOARDX+2*NTAILLE*MULTIPLICATOR+NTAILLE+1,MARGINBOARDY,RHINOCEROS,rhino.GetstockPiece());
            }
        if(win==3 || win==4) return win_display(win);
        m_BG.display(buffer, GetdisplayMod(),m_ecran);
        if(GetdisplayMod()) blit(buffer,screen,0,0,0,0, SCREEN_W, SCREEN_H);
    }


}

void Game::reset()
{
    for(int y=0;y<NTAILLE;y++)
    {
        for(int x=0;x<NTAILLE;x++)
        {
            if(m_BG.Getmap(x,y))
                m_BG.Setmap(x,y,NULL);



        }
    }
    for(int i=1;i<4;i++)
        {
            m_BG.Setmap(i,2,new Mountain(NULL));
        }
}


void Game::test()
{
    if(m_Graphic->GetRhn())std::cout<<"LE rhnino existe bordel!";

    blit(m_Graphic->GetRhn(),screen,0,0,100,100,m_Graphic->GetRhn()->w,m_Graphic->GetRhn()->h);
    textout(screen, font, "TEST", 0, 50, WHITE);

}

void Game::homepage(int x0,int y0)
{

            for(int y=0;y<y0;y++){std::cout<<std::endl;}


            for(int x=0;x<x0;x++){std::cout<<" ";} std::cout<<"   \xDB\xDB\xDB\xDB\xDB   "<<"   \xDB\xDB\xDB\xDB\xDB\xDB  "<<"     \xDB\xDB  "<<"   \xDB       \xDB"<<std::endl;
             for(int x=0;x<x0;x++){std::cout<<" ";}std::cout<<"\xDB\xDB         "<<"      \xDB    "<<"    \xDB\xDB\xDB  "<<"  \xDB \xDB     \xDB \xDB"<<std::endl;
            for(int x=0;x<x0;x++){std::cout<<" ";} std::cout<<"\xDB          "<<"     \xDB\xDB   "<<"    \xDB \xDB\xDB  "<<" \xDB\xDB  \xDB\xDB  \xDB\xDB \xDB\xDB"<<std::endl;
            for(int x=0;x<x0;x++){std::cout<<" ";} std::cout<<"\xDB\xDB         "<<"     \xDB    "<<"   \xDB\xDB \xDB\xDB  "<<" \xDB\xDB   \xDB \xDB   \xDB\xDB"<<std::endl;
             for(int x=0;x<x0;x++){std::cout<<" ";}std::cout<<"   \xDB\xDB\xDB     "<<"     \xDB    "<<"   \xDB  \xDB\xDB  "<<" \xDB\xDB    \xDB\xDB   \xDB\xDB"<<std::endl;
           for(int x=0;x<x0;x++){std::cout<<" ";}  std::cout<<"     \xDB\xDB\xDB    "<<"   \xDB     "<<"  \xDB\xDB  \xDB\xDB  "<<" \xDB\xDB    \xDB\xDB   \xDB\xDB"<<std::endl;
            for(int x=0;x<x0;x++){std::cout<<" ";} std::cout<<"      \xDB\xDB    "<<"   \xDB     "<<"  \xDB\xDB\xDB\xDB\xDB\xDB  "<<" \xDB\xDB    \xDB    \xDB\xDB"<<std::endl;
           for(int x=0;x<x0;x++){std::cout<<" ";}  std::cout<<"      \xDB\xDB    "<<"  \xDB\xDB     "<<" \xDB\xDB\xDB   \xDB  "<<"\xDB\xDB         \xDB\xDB"<<std::endl;
           for(int x=0;x<x0;x++){std::cout<<" ";}  std::cout<<"      \xDB     "<<"  \xDB      "<<" \xDB     \xDB  "<<"\xDB\xDB         \xDB\xDB"<<std::endl;
           for(int x=0;x<x0;x++){std::cout<<" ";}  std::cout<<"\xDB\xDB\xDB\xDB\xDB       "<<"\xDB\xDB\xDB\xDB\xDB    "<<"\xDB\xDB     \xDB  "<<"\xDB\xDB         \xDB\xDB"<<std::endl<<std::endl<<std::endl;
           for(int x=0;x<x0+8;x++){std::cout<<" ";} std::cout<<"PRESS ANY KEY TO CONTINUE:";
   m_ecran->showCursor(false);
   while(!m_ecran->isKeyboardPressed());
    m_ecran->getInputKey();
    m_ecran->showCursor(true);
    system("cls");

}
