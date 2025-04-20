#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

struct Bullet {
    sf::RectangleShape shape;
    Bullet(float x, float y) {
        shape.setSize(sf::Vector2f(5.f, 10.f));
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(x, y);
    }
};

struct Enemy {
    sf::RectangleShape shape;
    Enemy(float x, float y) {
        shape.setSize(sf::Vector2f(40.f, 40.f));
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(x, y);
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Shooting Game");
    window.setFramerateLimit(60);

    // Player
    sf::RectangleShape player(sf::Vector2f(50.f, 50.f));
    player.setFillColor(sf::Color::Blue);
    player.setPosition(WINDOW_WIDTH / 2.f - 25.f, WINDOW_HEIGHT - 60.f);

    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;

    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    int score = 0;

    sf::Clock clock;
    float enemySpawnTimer = 0.f;
    bool gameOver = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (!gameOver) {
            // Player movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player.getPosition().x > 0)
                player.move(-5.f, 0.f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player.getPosition().x + player.getSize().x < WINDOW_WIDTH)
                player.move(5.f, 0.f);

            // Shooting
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                if (bullets.empty() || bullets.back().shape.getPosition().y < player.getPosition().y - 50)
                    bullets.push_back(Bullet(player.getPosition().x + 22.f, player.getPosition().y));
            }

            // Update bullets
            for (size_t i = 0; i < bullets.size(); i++) {
                bullets[i].shape.move(0.f, -10.f);
                if (bullets[i].shape.getPosition().y < 0) {
                    bullets.erase(bullets.begin() + i);
                    i--;
                }
            }

            // Enemy spawning
            enemySpawnTimer += clock.restart().asSeconds();
            if (enemySpawnTimer >= 1.f) {
                float enemyX = static_cast<float>(rand() % (WINDOW_WIDTH - 40));
                enemies.push_back(Enemy(enemyX, 0));
                enemySpawnTimer = 0.f;
            }

            // Update enemies
            for (size_t i = 0; i < enemies.size(); i++) {
                enemies[i].shape.move(0.f, 2.f);
                if (enemies[i].shape.getPosition().y > WINDOW_HEIGHT) {
                    gameOver = true;
                    break;
                }
            }

            // Bullet-enemy collision
            for (size_t i = 0; i < bullets.size(); i++) {
                for (size_t j = 0; j < enemies.size(); j++) {
                    if (bullets[i].shape.getGlobalBounds().intersects(enemies[j].shape.getGlobalBounds())) {
                        bullets.erase(bullets.begin() + i);
                        enemies.erase(enemies.begin() + j);
                        score += 10;
                        i--;
                        break;
                    }
                }
            }
        }

        // Render
        window.clear();
        window.draw(player);
        for (auto& b : bullets) window.draw(b.shape);
        for (auto& e : enemies) window.draw(e.shape);

        scoreText.setString("Score: " + std::to_string(score));
        window.draw(scoreText);

        if (gameOver) {
            sf::Text gameOverText;
            gameOverText.setFont(font);
            gameOverText.setCharacterSize(40);
            gameOverText.setFillColor(sf::Color::Red);
            gameOverText.setString("Game Over!");
            gameOverText.setPosition(WINDOW_WIDTH / 2.f - 100.f, WINDOW_HEIGHT / 2.f - 50.f);
            window.draw(gameOverText);
        }

        window.display();
    }

    return 0;
}