#include <SFML/Graphics.hpp>
#include <string>
#include "BouncingBallScene.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 1024), "SFML works!");
	BouncingBallScene scene(&window);
	sf::Clock clock;
	sf::Time time;
	float dt;
	float fpsUpdate = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		time = clock.restart();
		dt = time.asSeconds();

		fpsUpdate += dt;
		if (fpsUpdate >= 0.3)
		{
			window.setTitle(std::to_string(1/dt));
			fpsUpdate = 0;
		}

		scene.Update(dt);
		window.clear();
		scene.Draw();
		window.display();
	}

	return 0;
}
