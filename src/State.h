#ifndef STATE_H
#define STATE_H


#include "Player.h"


class State
{
private:

protected:
    std::stack<State*>* states;
    sf::RenderWindow * window; // îêíî
    //std::map<std::string, int>* supportedKeys;
    //std::map<std::string, int> keybinds;
    bool quit; // ïåðåìåíàÿ îòâå÷àþùàÿ çà íàõîæäåíèè â òåêóùåì ñòîñòîÿíèè (state)

    //res
    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;



    std::vector<sf::Texture> textures;

    //funcs
    //virtual void keybinds() = 0;

public:
    State(sf::RenderWindow * window,std::stack<State*>* states); // êîíñòðóêòîð ïðèíèìàåò íà âõîä sfml îêíî
    virtual ~State();// âèðòóàëüíûé äèñòðóêòîð

    const bool& getQuit() const; // ïîëó÷èòü çíà÷åíèå quit âûõîäà èç ñîñòîÿíèÿ

    virtual void checkForQuit(); // ôóíêöèÿ ïðîâåðêè íà êîíåö ñîñòîÿíèÿ

    //ôóíêöèè êîòîðûå îáÿçàòåëüíî äîëæíû áûòü ïåðåîïðåäåëåíû
    virtual void endState() = 0; //çàâåðøåíèå òåêóùåãî ñîñòîÿíèÿ
    virtual void updateMousePosition();
    virtual void updateInput(const float& time) = 0; // ôóíêöèÿ êîòîðàÿ îòâå÷àåò çà îáíîâëåíèå âõîäÿùåé èíôîðìàöèè
    virtual void update(const float& time) = 0; // àïäåéò ïðèíèìàåò âðåìÿ delta time (Dt)
    virtual void render(sf::RenderWindow * window) = 0; // ôóíêöèÿ ðåíäåðà
};

#endif
