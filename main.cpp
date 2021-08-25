#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <math.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <SFML/Network.hpp>

class Ball
{
public:
    Ball(float x, float y, float dx, float dy, float speed, int score ,sf::Color color) {
    inhole=false;
    this->x = x;
    this->y = y;
    this->dx = dx;
    this->dy = dy;
    this->speed = speed;
    this->score = score;
    this->color = color;
}

float get_x() {
    return this->x;
}

float get_y() {
    return this->y;
}

void reverse_dy() {
    this->dy = - this->dy;
}

void reverse_dx() {
    this->dx = - this->dx;
}

void move() {
    this->x += this->dx * speed/2;
    this->y += this->dy * speed/2;
    speed-=0.1;
    if(speed<=0)
    {
        speed=0;
        dx=0;
        dy=0;
    }
}

void set_x(float x) {
    this->x = x;
}

void set_y(float y) {
    this->y = y;
}

void set_dx(float dx)
{
    this->dx=dx;
}

void set_dy(float dy)
{
    this->dy=dy;
}

float get_dx()
{
    return this->dx;
}

float get_dy()
{
    return this->dy;
}

void set_speed(float speed)
{
    this->speed=speed;
}

float get_speed()
{
    return this->speed;
}

void go_inhole()
{
    this->inhole=true;
}

bool get_inhole()
{
    return this->inhole;
}

void set_inhole()
{
    this->inhole=false;
}

void setting_inhole(bool v)
{
    this->inhole=v;
}

sf::Color get_color(){
    return this->color;
}

int get_score()
{
    return this->score;
}

private:
    float x, y, dx, dy, speed;
    int score;
    sf::Color color;
    bool inhole;
};

float distance(float x,float y,float x1,float y1)
{
    return (x-x1)*(x-x1)+(y-y1)*(y-y1);
}

bool check_hole(int a,int *b)
{
    for(int i=0;i<a;i++)
    {
        if(b[i]==0 or b[i]>15)
            return false;
    }
    return true;
}

class Game
{
public:
    Game(){
    scores[0] = scores[1] = 0;
    ball=new Ball *[22];
    ball[1]=new Ball(539.5,171.5,0,0,0,1,sf::Color::Red);
    ball[2]=new Ball(549.5,165.5,0,0,0,1,sf::Color::Red);
    ball[3]=new Ball(549.5,177.5,0,0,0,1,sf::Color::Red);
    ball[4]=new Ball(559.5,183.5,0,0,0,1,sf::Color::Red);
    ball[5]=new Ball(559.5,171.5,0,0,0,1,sf::Color::Red);
    ball[6]=new Ball(559.5,159.5,0,0,0,1,sf::Color::Red);
    ball[7]=new Ball(569.5,189.5,0,0,0,1,sf::Color::Red);
    ball[8]=new Ball(569.5,177.5,0,0,0,1,sf::Color::Red);
    ball[9]=new Ball(569.5,165.5,0,0,0,1,sf::Color::Red);
    ball[10]=new Ball(569.5,153.5,0,0,0,1,sf::Color::Red);
    ball[11]=new Ball(579.5,195.5,0,0,0,1,sf::Color::Red);
    ball[12]=new Ball(579.5,183.5,0,0,0,1,sf::Color::Red);
    ball[13]=new Ball(579.5,171.5,0,0,0,1,sf::Color::Red);
    ball[14]=new Ball(579.5,159.5,0,0,0,1,sf::Color::Red);
    ball[15]=new Ball(579.5,147.5,0,0,0,1,sf::Color::Red);
    ball[16]=new Ball(141.9,229.5,0,0,0,2,sf::Color::Yellow); //yellow
    ball[17]=new Ball(141.9,171.5,0,0,0,4,sf::Color(121,85,72)); //brown
    ball[18]=new Ball(141.9,113.5,0,0,0,3,sf::Color::Cyan); //green
    ball[19]=new Ball(350.5,171.5,0,0,0,5,sf::Color::Blue);//blue
    ball[20]=new Ball(528.f,171.5,0,0,0,6,sf::Color(255,192,203)); //pink
    ball[21]=new Ball(641.7,171.5,0,0,0,7,sf::Color::Black); //black
}
void get_whiteball(sf::RenderWindow *window)
{
    bool v=true;
    sf::Event event;
    while(v)
    {
        if (window->pollEvent(event) and event.type==sf::Event::MouseButtonPressed and distance(event.mouseButton.x-5.5,event.mouseButton.y-5.5,147.4,177)<=3364 and event.mouseButton.x<=147.4)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    v=false;
                    ball[0]=new Ball(event.mouseButton.x-5.5,event.mouseButton.y-5.5,0,0,0,0,sf::Color::White);
                }
            }
    }
}
int get_scores(int player) {
    return this->scores[player];
}

void set_score(int player,int value)
{
    this->scores[player]+=value;
}

Ball** get_ball(){
    return this->ball;
}

int move() {
    bool v=true;
    first=0;
    float x1,y1,x2,y2,dx1,dy1,dx2,dy2,dx3,dy3,dx4,dy4,v1,v2;
    for(int i=0;i<22;i++)
    {
        this->ball[i]->move();
        if(ball[i]->get_x()<=357 and ball[i]->get_x()>=344 and (ball[i]->get_y()>=343 or ball[i]->get_y()<=0))
        {
            ball[i]->go_inhole();
            holeball[x]=i;x++;
        }
        else if(ball[i]->get_x()<=6.5 and (ball[i]->get_y()>=342.5 or ball[i]->get_y()<=2.5))
        {
            ball[i]->go_inhole();
            holeball[x]=i;x++;
        }
        else if(ball[i]->get_x()>=700 and (ball[i]->get_y()>=342.5 or ball[i]->get_y()<=2.5))
        {
            ball[i]->go_inhole();
            holeball[x]=i;x++;
        }
        else if(!ball[i]->get_inhole() and (ball[i]->get_y()<= 0 || ball[i]->get_y()>=343))
            this->ball[i]->reverse_dy();
        else if(!ball[i]->get_inhole() and (ball[i]->get_x()<= 0 || ball[i]->get_x()>=701))
            this->ball[i]->reverse_dx();
        for(int j=i+1;j<22;j++)
        {
            if(i!=j and distance(ball[i]->get_x(),ball[i]->get_y(),ball[j]->get_x(),ball[j]->get_y())<121)
            {
                if(i==0 and v)
                {
                    v=false;
                    first=j;
                }
                x1=ball[i]->get_x();y1=ball[i]->get_y();
                dx1=ball[i]->get_dx();dy1=ball[i]->get_dy();
                x2=ball[j]->get_x();y2=ball[j]->get_y();
                dx2=ball[j]->get_dx();dy2=ball[j]->get_dy();
                v1=ball[i]->get_speed();v2=ball[j]->get_speed();
                if(!((x2-x1)*dx1+(y2-y1)*dy1<0 or (x1-x2)*dx2+(y1-y2)*dy2<0) and distance(x1,y1,x2,y2)!=0)
                {
                //std::cout<<i<<"  "<<j<<"  "<<x1<<"  "<<y1<<"  "<<x2<<"  "<<y2<<"  "<<distance(x1,y1,x2,y2)<<"\n";
                dx3=v1*dx1-(((v1*dx1-v2*dx2)*(x1-x2)+(v1*dy1-v2*dy2)*(y1-y2))*(x1-x2)/distance(x1,y1,x2,y2));
                dy3=v1*dy1-(((v1*dx1-v2*dx2)*(x1-x2)+(v1*dy1-v2*dy2)*(y1-y2))*(y1-y2)/distance(x1,y1,x2,y2));
                dx4=v2*dx2-(((v1*dx1-v2*dx2)*(x1-x2)+(v1*dy1-v2*dy2)*(y1-y2))*(x2-x1)/distance(x1,y1,x2,y2));
                dy4=v2*dy2-(((v1*dx1-v2*dx2)*(x1-x2)+(v1*dy1-v2*dy2)*(y1-y2))*(y2-y1)/distance(x1,y1,x2,y2));
                ball[i]->set_speed(sqrt((dx3*dx3+dy3*dy3)));
                ball[j]->set_speed(sqrt((dx4*dx4+dy4*dy4)));
                if(ball[i]->get_speed()!=0)
                {
                    ball[i]->set_dx(dx3/ball[i]->get_speed());
                    ball[i]->set_dy(dy3/ball[i]->get_speed());
                }
                else
                {
                    ball[i]->set_dx(0);
                    ball[i]->set_dy(0);
                }
                if(ball[j]->get_speed()!=0)
                {
                    ball[j]->set_dx(dx4/ball[j]->get_speed());
                    ball[j]->set_dy(dy4/ball[j]->get_speed());
                }
                else
                {
                    ball[j]->set_dx(0);
                    ball[j]->set_dy(0);
                }
                }
            }
        }
    }
    for(int i=0;i<22;i++)
    {
        if(!ball[i]->get_inhole() and ball[i]->get_y()<= 0)
            ball[i]->set_y(0);
        else if(!ball[i]->get_inhole() and ball[i]->get_y()>=343)
            ball[i]->set_y(343);
        else if(!ball[i]->get_inhole() and ball[i]->get_x()>=701)
            ball[i]->set_x(701);
        else if(!ball[i]->get_inhole() and ball[i]->get_x()<= 0)
            ball[i]->set_x(0);
    }
    /*for(int i=0;i<22;i++)
    {
        x1=ball[i]->get_x();y1=ball[i]->get_y();
        std::cout<<i<<"  "<<x1<<"  "<<y1<<"\n";
    }*/
    /*for(int i=0;i<22;i++)
    {
        for(int j=0;j<22;j++)
        {
            if(i!=j and distance(ball[i]->get_x(),ball[i]->get_y(),ball[j]->get_x(),ball[j]->get_y())<121)
            {
                x1=ball[i]->get_x();y1=ball[i]->get_y();
                x2=ball[j]->get_x();y2=ball[j]->get_y();
                ball[i]->set_x(11*(x1-x2)/distance(x1,y1,x2,y2)-((x1+x2)/2));
                ball[i]->set_y(11*(y1-y2)/distance(x1,y1,x2,y2)-((y1+y2)/2));
                ball[j]->set_x(11*(x2-x1)/distance(x1,y1,x2,y2)-((x1+x2)/2));
                ball[j]->set_y(11*(y2-y1)/distance(x1,y1,x2,y2)-((y1+y2)/2));
            }
        }
    }*/
    return first;
}

int* get_holeball()
{
    this->x=0;
    return holeball;
}

int get_x()
{
    return this->x;
}

private:
    int scores[2],first;
    Ball **ball;
    int holeball[20],x=0;
};

int value_hole(int a,int *b,Game *game)
{
    int maxx=0;
    for(int i=0;i<a;i++)
    {
        if(game->get_ball()[b[i]]->get_score()>maxx)
            maxx=game->get_ball()[b[i]]->get_score();

    }
    return(maxx);
}
void check_balls(Game *game)
{
    float x[]={141.9,141.9,141.9,350.5,528.f,641.7};
    float y[]={229.5,171.5,113.5,171.5,171.5,171.5};
    for(int i=16;i<22;i++)
    {
        if(game->get_ball()[i]->get_inhole())
        {
            game->get_ball()[i]->set_x(x[i-16]);
            game->get_ball()[i]->set_y(y[i-16]);
            //game->get_ball()[0]->set_dx(0);
            //game->get_ball()[0]->set_dy(0);
            //game->get_ball()[0]->set_speed(0);
            game->get_ball()[i]->set_inhole();
        }
    }
}

class Resource {
public:
    Resource(Game *game) {
    this->game = game;
}

void set(std::string str) {
    std::stringstream inp(str);
    float ball_x, ball_y;
    bool v;
    for(int i=0;i<22;i++)
    {
        inp >> ball_x >> ball_y >> v;
        this->game->get_ball()[i]->set_x(ball_x);
        this->game->get_ball()[i]->set_y(ball_y);
        this->game->get_ball()[i]->setting_inhole(v);
    }
}

std::string get() {
    std::stringstream res;
    for(int i=0;i<22;i++)
    {
        res << this->game->get_ball()[i]->get_x()<<" "
            << this->game->get_ball()[i]->get_y()<<" "
            << this->game->get_ball()[i]->get_inhole();
    }
    return res.str();
}
private:
    Game* game;
};

class Network {
public:
    Network(Resource *resource) {
    this->resource = resource;
    this->is_server = true;
    this->ip = "0.0.0.0";

    this->listener = new sf::TcpListener;

    listener->listen(12345);
}

Network(Resource *resource, std::string ip) {
    this->resource = resource;
    this->is_server = false;
    this->ip = ip;
}

void listen() {
    if (this->is_server) {
        this->socket = new sf::TcpSocket;
        this->listener->accept(*this->socket);
    }
}

void connect() {
    if (not this->is_server){
        this->socket = new sf::TcpSocket;
        this->socket->connect(this->ip, 12345);
    }
}

void send() {
    std::string message = this->resource->get();
    char* c_message = new char[(int)message.size() + 1];

    for (unsigned int i = 0; i < message.size(); i++)
        c_message[i] = message[i];

    this->socket->send(c_message, (int)message.size());

    delete c_message;
}

void receive() {
    char data[1000];
    size_t received;
    this->socket->receive(data, 1000, received);

    if (received != 0) {
        std::string message = std::string(data);
        this->resource->set(message);
    }
}
private:
    Resource* resource;
    bool is_server;
    std::string ip;
    sf::TcpListener* listener;
    sf::TcpSocket* socket;
};


void renderer(sf::RenderWindow *window, Game *game)
{
    Ball **ball = game->get_ball();
    sf::CircleShape shape;
    for(int i=0;i<22;i++)
    {
        if(ball[i]->get_inhole()==false)
        {
            shape.setRadius(5.5);
            shape.setPosition(ball[i]->get_x(), ball[i]->get_y());
            shape.setFillColor(ball[i]->get_color());
            window->draw(shape);
        }
    }
}


int main()
{
    int a,first;
    float b;
    int player=0,turn=0;
    bool v,value;
    std::cin >> a;
    float x,y;
    sf::RenderWindow window(sf::VideoMode(712,354), "Snooker");
    sf::CircleShape shape[7];
    sf::RectangleShape line(sf::Vector2f(354,1));
    sf::RectangleShape pak(sf::Vector2f(120,120));
    pak.setPosition(147,118);
    pak.setFillColor(sf::Color::Green);
    line.rotate(90);
    line.setPosition(147.4,0);
    shape[6].setRadius(58);
    shape[6].setFillColor(sf::Color::Green);
    shape[6].setOutlineThickness(1);
    shape[6].setOutlineColor(sf::Color::White);
    shape[6].setPosition(89.4,119);
    for(int i=0;i<6;i++)
    {
        shape[i].setRadius(12);
        shape[i].setFillColor(sf::Color::Black);
    }
    shape[0].setPosition(-12,-12);
    shape[1].setPosition(344,-12);
    shape[2].setPosition(700,-12);
    shape[3].setPosition(-12,342);
    shape[4].setPosition(344,342);
    shape[5].setPosition(700,342);
    window.clear(sf::Color::Green);
    for(int i=0;i<7;i++)
        window.draw(shape[i]);
    window.draw(line);
    window.draw(pak);
    window.display();
    Game *game = new Game();
    game->get_whiteball(&window);
    window.clear(sf::Color::Green);
    for(int i=0;i<7;i++)
            window.draw(shape[i]);
    window.draw(line);
    window.draw(pak);
    renderer(&window,game);
    window.display();
    Resource* resource = new Resource(game);
    Network* network;
    if (a == 0){
        network = new Network(resource);
        network->listen();
    }
    else{
        network = new Network(resource, "127.0.0.1");
        network->connect();
    }

    sf::Event event;
    std::cout<<"player "<<player+1<<" and turn is "<<turn+1<<"\n";
    while (window.isOpen())
    {
        value=false;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {

                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    value=true;
                    /*do
                    {
                        std::cout<<"Enter a number between 1-20 : ";
                        std::cin>>b;
                    }while(b<1 or b>20);*/
                    x=event.mouseButton.x-(game->get_ball()[0]->get_x()+5.5);
                    y=event.mouseButton.y-(game->get_ball()[0]->get_y()+5.5);
                    b=sqrt((x*x+y*y))/10;
                    if(b>25)
                        b=25;
                    game->get_ball()[0]->set_speed(b);
                    game->get_ball()[0]->set_dx(x/sqrt(x*x+y*y));
                    game->get_ball()[0]->set_dy(y/sqrt(x*x+y*y));
                }
            }
        }
        // dar sorat vared kardan dorost vorodi ha ejra mishe
        if(value)
        {
        v=true;
        first=0;
        while(v)
        {
            if(first==0)
                first=game->move();
            else
                game->move();
            network->send();
            network->receive();
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            window.clear(sf::Color::Green);
            for(int i=0;i<7;i++)
                window.draw(shape[i]);
            window.draw(line);
            window.draw(pak);
            renderer(&window,game);
            window.display();
            v=false;
            for(int i=0;i<22;i++)
            {
                if(game->get_ball()[i]->get_speed()!=0)
                {
                    v=true;break;
                }
            }
        }
        a=game->get_x();
        if(first==0 and !(game->get_ball()[0]->get_inhole()))
        {
            game->set_score(player,-4);
            player++;
            player=player%2;
            turn=0;
        }
        else if(game->get_ball()[0]->get_inhole())
        {
            v=true;
            game->set_score(player,-1*std::max(4,(game->get_ball()[first]->get_score())));
            player++;
            player=player%2;
            turn=0;
            game->get_whiteball(&window);
            /*while(v)
            {
                if (window.pollEvent(event) and event.type==sf::Event::MouseButtonPressed and distance(event.mouseButton.x-5.5,event.mouseButton.y-5.5,147.4,177)<=3364 and event.mouseButton.x<=147.4)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        v=false;
                        game->get_ball()[0]->set_x(event.mouseButton.x-5.5);
                        game->get_ball()[0]->set_y(event.mouseButton.y-5.5);
                        //game->get_ball()[0]->set_dx(0);
                        //game->get_ball()[0]->set_dy(0);
                        //game->get_ball()[0]->set_speed(0);
                        game->get_ball()[0]->set_inhole();
                    }
                }
            }*/
        }
        else if(turn==0)
        {
            if((first>0 and first<=15) and a!=0 and check_hole(a,game->get_holeball()))
            {
                turn++;
                game->set_score(player,1);
            }
            else if((first>0 and first<=15) and a==0 and check_hole(a,game->get_holeball()))
            {
                turn=0;
                player++;
                player=player%2;
            }
            else
            {
                turn=0;
                game->set_score(player,-1*std::max(value_hole(a,game->get_holeball(),game),game->get_ball()[first]->get_score()));
                player++;
                player=player%2;
            }
        }
        else if(turn==1)
        {
            if(a==1 and game->get_holeball()[0]==first)
            {
                turn=0;
                game->set_score(player,game->get_ball()[first]->get_score());
            }
            else if(a==0 and first>15)
            {
                turn=0;
                player++;
                player=player%2;
            }
            else
            {
                turn=0;
                game->set_score(player,-1*std::max(std::max(value_hole(a,game->get_holeball(),game),game->get_ball()[first]->get_score()),4));
                player++;
                player=player%2;
            }
        }
        check_balls(game);
        window.clear(sf::Color::Green);
        for(int i=0;i<7;i++)
            window.draw(shape[i]);
        window.draw(line);
        window.draw(pak);
        renderer(&window,game);
        window.display();
        std::cout<<"player 1 score is "<<game->get_scores(0)<<" player 2 score is "<<game->get_scores(1)<<"\n";
        std::cout<<"player "<<1+player<<" and turn is "<<1+turn<<"\n";
        }
    }
    return 0;
}
