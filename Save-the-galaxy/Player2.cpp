#include "Player2.h"

void Player2::initVariables()
{
	this->movementSpeed = 2.f;

	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;

	this->hpMax = 100;
	this->hp = this->hpMax;
}

void Player2::initTexture()
{
	//Load a texture from file
	if (!this->texture.loadFromFile("Textures/ship2.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void Player2::initSprite()
{
	//Set the texture to the sprite
	this->sprite.setTexture(this->texture);

	//Resize the sprite
	this->sprite.scale(0.25f, 0.25f);
}

Player2::Player2()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Player2::~Player2()
{

}

const sf::Vector2f& Player2::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player2::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Player2::getHp() const
{
	return this->hp;
}

const int& Player2::getHpMax() const
{
	return this->hpMax;
}

void Player2::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Player2::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player2::setHp(const int hp)
{
	this->hp = hp;
}

void Player2::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

void Player2::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const bool Player2::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}

	return false;
}

void Player2::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 0.5f;
}

//Functions
void Player2::update()
{
	this->updateAttack();
}

void Player2::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
