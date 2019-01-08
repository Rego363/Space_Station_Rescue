#include "../Header/Player.h"

Player::Player()
{
	m_mass = 20.0f;
	m_speed = 10.0f;
	m_turnSpeed = 3.0f;
	m_size = sf::Vector2f(25, 50);
	m_pos = sf::Vector2f(50, 50);
	m_velocity = sf::Vector2f(0, 0);
	m_accel = sf::Vector2f(0, 0);
	m_idleRect = sf::IntRect(0, 0, 64, 96);
	//m_rect.setFillColor(sf::Color::Green);
	m_gravity = sf::Vector2f(0, 0.1f * m_mass);
	m_jumpForce = sf::Vector2f(0, -5.0f * m_mass);
	m_moveForce = sf::Vector2f(0.5f * m_mass, 0.0f);
	m_friction = sf::Vector2f(0.3f * m_mass, 0.0f);
	m_direction = 1.0f;

	if (!m_Texture.loadFromFile("Images/astronaut.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	m_Sprite.setTextureRect(m_idleRect);
	m_Sprite.setOrigin(m_Sprite.getLocalBounds().width / 2, m_Sprite.getLocalBounds().height / 2);
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(m_pos);

}

Player::~Player()
{

}


void Player::render(sf::RenderWindow & window)
{
	window.draw(m_Sprite);
}

void Player::applyForce(sf::Vector2f force)
{
	sf::Vector2f f = force / m_mass;
	m_accel += f;
}

void Player::update()
{	
	moveForward();
	turnLeft();
	turnRight();
	
	m_velocity += m_accel;
	m_pos += m_velocity;
	m_accel = sf::Vector2f(0.0f, 0.0f);

	m_Sprite.setPosition(m_pos);
}

void Player::checkCollision(sf::Vector2f size, sf::Vector2f pos)
{
	float w = 0.5f * (m_size.x + size.x);
	float h = 0.5f * (m_size.y + size.y);
	float dx = (m_pos.x + (m_size.x / 2)) - (pos.x + (size.x / 2));
	float dy = (m_pos.y + (m_size.y / 2)) - (pos.y + (size.y / 2));

	if (abs(dx) <= w && abs(dy) <= h)
	{
		/* collision! */
		float wy = w * dy;
		float hx = h * dx;

		if (wy > hx)
		{
			if (wy > -hx)
			{
				// Top 
				m_velocity.y = 0.0f;
				m_pos.y = pos.y + size.y;
			}
			else if ( wy < -hx)
			{
				// Left
				m_velocity.x = 0.0f;
				m_pos.x = pos.x - m_size.x;
			}
		}
		else if (wy < hx)
		{
			if (wy > -hx)
			{
				// Right
				m_velocity.x = 0.0f;
				m_pos.x = pos.x + size.x;
			}
			else if(wy < -hx)
			{
				// Bottom
				m_pos.y = pos.y - m_size.y;
			}
		}
	}

}

void Player::moveForward()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		int x = m_pos.x + sin(m_Sprite.getRotation()*3.14159265 / 180) * -3;
		int y = m_pos.y + cos(m_Sprite.getRotation()*3.14159265 / 180) * 3;
		m_pos = sf::Vector2f(x, y);
	}
}

void Player::turnLeft()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_Sprite.setRotation(m_Sprite.getRotation() - m_turnSpeed);

		if (m_Sprite.getRotation() <= 0.0f)
		{
			m_Sprite.setRotation(360.0f);
		}

	}
}

void Player::turnRight()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_Sprite.setRotation(m_Sprite.getRotation() + m_turnSpeed);

		if (m_Sprite.getRotation() >= 360.0f)
		{
			m_Sprite.setRotation(0.0f);
		}
	}
}

void Player::fire()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{

	}
}