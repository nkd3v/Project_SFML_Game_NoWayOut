#pragma once
class AttributeComponent
{
public:
	
	int hp;
	int hpMax;
	int damageMin;
	int damageMax;

	int moveSpeed;
	int shootSpeed;

	int score;

	AttributeComponent(int hpMax = 4, int damageMin = 1, int damageMax = 2, int moveSpeed = 1, int shootSpeed = 1);
	virtual ~AttributeComponent();

	void loseHP(const int changeHP);
	void gainHP(const int changeHP);

	void setScore(int newScore);
	int getScore();

	const bool isDead() const;

	void update();
};

