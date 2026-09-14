#include "upgrade_player.h"
#include <cstdlib>

upgrade_player::upgrade_player(player * player1){
    this->more_fireball_damage = new button(500, 400, 80, 30, BLUE, "More Fireball Damage", 10);
    this->more_fireball_damage->onClick = [player1](){player1->fireball_damage++;};
    this->button_list.push_back(this->more_fireball_damage);
    this->new_fireball = new button(650, 400, 80, 30, BLUE, "New Fireball", 10);
    this->new_fireball->onClick = [player1](){player1->fireball_list.push_back(new fireball(player1->fireball_amount));
        player1->fireball_amount++;};
    this->button_list.push_back(this->new_fireball);
    this->faster_push_cooldown = new button(750, 400, 80, 30, BLUE, "Decrease Push Cooldown", 10);
    this->faster_push_cooldown->onClick = [player1](){player1->push_refresh--;};
    this->button_list.push_back(this->faster_push_cooldown);
    this->more_push_damage = new button(900, 400, 80, 30, BLUE, "More Push Damage", 10);
    this->more_push_damage->onClick = [player1](){player1->push_damage++;};
    this->button_list.push_back(this->more_push_damage);
    this->faster_dash_cooldown = new button(500, 500, 80, 30, BLUE, "Decrease Dash Cooldown", 10);
    this->faster_dash_cooldown->onClick = [player1](){player1->dash_refresh--;};
    this->button_list.push_back(faster_dash_cooldown);
    this->more_dash_damage = new button(650, 500, 80, 30, BLUE, "More Dash Damage", 10);
    this->more_dash_damage->onClick = [player1](){player1->dash_damage++;};
    this->button_list.push_back(this->more_dash_damage);
    this->new_arrow = new button(800, 500, 80, 30, BLUE, "New Arrow", 10);
    this->new_arrow->onClick = [player1](){player1->arrow_list.push_back(new arrow());
        player1->arrow_amount++;};
    this->button_list.push_back(this->new_arrow);
    this->more_arrow_damage = new button(900, 500, 80, 30, BLUE, "More Arrow Damage", 10);
    this->more_arrow_damage->onClick = [player1](){player1->arrow_damage++;};
    this->button_list.push_back(this->more_arrow_damage);
    this->more_cannon_balls = new button(500, 600, 80, 30, BLUE, "More Cannon Balls", 10);
    this->more_cannon_balls->onClick = [player1](){player1->cannon_ball_amount++;
        player1->cannon_ball_list.push_back(new cannon_ball(player1->x, player1->y, player1->cannon_ball_amount));};
    this->button_list.push_back(this->more_cannon_balls);
    this->faster_cannon_ball_cooldown = new button(700, 600, 80, 30, BLUE, "Faster Cannon Ball Cooldown", 10);
    this->faster_cannon_ball_cooldown->onClick = [player1](){player1->cannon_ball_refresh--;};
    this->button_list.push_back(this->faster_cannon_ball_cooldown);
    
}


void upgrade_player::update(Vector2 mouse_position, player * player1){
    for(int i = 0; i < 3; i++){
        if(this->button_list[i]->update(mouse_position)){
            this->button_list[i]->onClick();
            player1->experience = 0;
            player1->experience_amount++;
        }
    }
}

void upgrade_player::draw(){
    for(int i = 0; i < 3; i++){
        this->button_list[i]->draw();
    }
}

upgrade_player::~upgrade_player(){
    for(int i = 0; i < this->button_list.size(); i++){
        delete this->button_list[i];
        this->button_list[i] = nullptr;
    }
    
}

void upgrade_player::refresh_buttons(){
    random_device rd;
    mt19937 g(rd());
    shuffle(this->button_list.begin(), this->button_list.end(), g);
    for(int i = 0; i < 3; i++){
        this->button_list[i]->x_position = 300 + i * 150;
        this->button_list[i]->y_position = 400;
    }
}


