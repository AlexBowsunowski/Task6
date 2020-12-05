#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

using namespace sf;

void fractal(std::vector<VertexArray>* a, int max_depth, int current_depth, double l, double m, double x, double y){
    if (current_depth == max_depth) return;
    VertexArray line(Lines, 2);
    line[0].position = Vector2f(x + l/4,y - m/2);
    line[0].color = Color::Blue;
    line[1].position = Vector2f(x + 3 * l / 4, y - m / 2);
    line[1].color = Color::Blue;
    a->push_back(line);
    VertexArray line1(Lines, 2);
    line1[0].position = Vector2f(x + l/4, y - m/2);
    line1[0].color = Color::Blue;
    line1[1].position = Vector2f(x + l/2, y);
    line1[1].color = Color::Blue;
    a->push_back(line1);
    VertexArray line2(Lines, 2);
    line2[0].position = Vector2f(x + 3*l/4, y - m/2);
    line2[0].color = Color::Blue;
    line2[1].position = Vector2f(x + l /2, y);
    line2[1].color = Color::Blue;
    a->push_back(line2);

    current_depth++;
    fractal(a, max_depth, current_depth, l /2, m / 2, x + l /4, y - m/ 2);
    fractal(a, max_depth, current_depth, l /2, m / 2, x, y);
    fractal(a, max_depth, current_depth, l /2, m / 2, x + l /2, y);

}



int main() {
    RenderWindow window(VideoMode(1000, 1000), "fractal");
    std::vector<VertexArray> fract;
    double x = 250;
    double y = 600;
    double l = 600;
    double m = 400;

    VertexArray line(Lines, 2);
    line[0].position = Vector2f(x,y);
    line[0].color = Color::Blue;
    line[1].position = Vector2f(x + l / 2, y - m);
    line[1].color = Color::Blue;
    fract.push_back(line);
    VertexArray line1(Lines, 2);
    line1[0].position = Vector2f(x + l/2, y - m);
    line1[0].color = Color::Blue;
    line1[1].position = Vector2f(x + l, y);
    line1[1].color = Color::Blue;
    fract.push_back(line1);
    VertexArray line2(Lines, 2);
    line2[0].position = Vector2f(x, y);
    line2[0].color = Color::Blue;
    line2[1].position = Vector2f(x + l, y);
    line2[1].color = Color::Blue;
    fract.push_back(line2);



    int depth;
    std::cout<<"Введите глубину рекурсии:\n";
    std::cin>>depth;

    fractal(&fract, depth, 0, l, m, x, y);


    while (window.isOpen()) {
        // Конструктор обработчика событий
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        // Вызовы функций
        window.clear();
        for(int i = 0; i < fract.size(); ++i){
            window.draw(fract[i]);
        }
        window.display();

    }

    return 0;
}
