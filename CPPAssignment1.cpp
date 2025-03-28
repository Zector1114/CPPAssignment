// CPPAssignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;


#pragma region Player
class PlayerCombat // Sophie
{
public:
    bool isDefending = false;
    float damage = 15;
    float healAmount = 30;
    int healTimer = 0;
    static float ReturnHealth();
    static float ReturnMaxHealth();
    void TakeDamage(float damage);
    void TurnEnd();
    void Heal();
private:
    static float currentHealth;
    static float maxHealth;
    int healTimerTurnAmount = 3;
};

float PlayerCombat::currentHealth = 100;
float PlayerCombat::maxHealth = 100;

float PlayerCombat::ReturnHealth() // Sophie
{
    return currentHealth;
}

float PlayerCombat::ReturnMaxHealth() // Sophie
{
    return maxHealth;
}

void PlayerCombat::TakeDamage(float damage) // Sophie
{
    if (isDefending) {
        currentHealth -= damage / 2;
    }
    else {
        currentHealth -= damage;
    }
}

void PlayerCombat::Heal() // Sophie
{
    currentHealth += healAmount;
    if (currentHealth > maxHealth) {currentHealth = maxHealth;}
    healTimer = healTimerTurnAmount;
}

void PlayerCombat::TurnEnd() //Sophie
{
    if (healTimer > 0) { healTimer--; }
}
#pragma endregion Player

#pragma region Monster
class Monster // Erik
{
public:
    Monster() {};
    bool isDefending = false;
    static float currentHealth;
    static float maxHealth;
    static string name;
    virtual void SetHealth();
    virtual void TakeDamage(float damage);
    virtual float DetermineMove(); // |
    virtual float MonsterAttack(float monsterDamage); // Polymorphism
    virtual float MonsterDefend(); // |
    virtual float ReturnHealth();
    virtual float ReturnMaxHealth();
    virtual string ReturnName();
};

float Monster::currentHealth = 100;
float Monster::maxHealth = 100;
string Monster::name = "Monster";

void Monster::SetHealth()
{
    currentHealth = maxHealth;
}

float Monster::DetermineMove() { return 1; } // Erik

float Monster::MonsterAttack(float monsterDamage) // Erik
{
    return monsterDamage;
}

float Monster::MonsterDefend() { return 1; } // Erik

void Monster::TakeDamage(float damage) {} // Erik

float Monster::ReturnHealth() { return currentHealth; }

float Monster::ReturnMaxHealth() { return maxHealth; }

string Monster::ReturnName() { return name; }

#pragma region Slime
class Slime : public Monster // Erik - Inheritance
{
public:
    bool isDefending = false;
    static float maxHealth;
    static float currentHealth;
    float monsterDamage = 5;
    static string name;
    void SetHealth() override;
    float MonsterAttack(float monsterDamage) override;
    void TakeDamage(float damage) override;
    float MonsterDefend() override;
    float DetermineMove() override;
    float ReturnHealth() override;
    float ReturnMaxHealth() override;
    string ReturnName() override;
};

float Slime::maxHealth = 100;
float Slime::currentHealth = 100;
string Slime::name = "Slime";

void Slime::SetHealth()
{
    currentHealth = maxHealth;
}

void Slime::TakeDamage(float damage)
{
    if (isDefending) currentHealth -= damage / 2;
    else currentHealth -= damage;
}

float Slime::MonsterAttack(float monsterDamage)
{
    cout << "The " << name << " attacked and did " << monsterDamage << " damage!\n\n";
    isDefending = false;
    return monsterDamage;
}

float Slime::MonsterDefend()
{
    cout << "The " << name << " defended!\n\n";
    isDefending = true;
    return 0;
}

float Slime::DetermineMove()
{
    if ((PlayerCombat::ReturnHealth() / PlayerCombat::ReturnMaxHealth()) - (currentHealth / maxHealth) >= 0.50)
    {
        return MonsterDefend();
    }
    else if ((PlayerCombat::ReturnHealth() / PlayerCombat::ReturnMaxHealth()) - (currentHealth / maxHealth) >= 0.30)
    {
        if (isDefending)
        {
            return MonsterAttack(monsterDamage);
        }
    }

    return MonsterAttack(monsterDamage);
}

float Slime::ReturnHealth() { return currentHealth; }

float Slime::ReturnMaxHealth() { return maxHealth; }

string Slime::ReturnName() { return name; }
#pragma endregion Slime

#pragma region Zombie
class Zombie : public Monster // Erik - Inheritance
{
public:
    bool isDefending = false;
    static float maxHealth;
    static float currentHealth;
    float monsterDamage = 7;
    static string name;
    void SetHealth() override;
    float MonsterAttack(float monsterDamage) override;
    void TakeDamage(float damage) override;
    float MonsterDefend() override;
    float DetermineMove() override;
    float ReturnHealth() override;
    float ReturnMaxHealth() override;
    string ReturnName() override;
};

float Zombie::maxHealth = 125;
float Zombie::currentHealth = 125;
string Zombie::name = "Zombie";

void Zombie::SetHealth()
{
    currentHealth = maxHealth;
}

void Zombie::TakeDamage(float damage)
{
    if (isDefending) currentHealth -= damage / 2;
    else currentHealth -= damage;
}

float Zombie::MonsterAttack(float monsterDamage)
{
    cout << "The " << name << " attacked and did " << monsterDamage << " damage!\n\n";
    isDefending = false;
    return monsterDamage;
}

float Zombie::MonsterDefend()
{
    cout << "The " << name << " defended!\n\n";
    isDefending = true;
    return 0;
}

float Zombie::DetermineMove()
{
    if ((PlayerCombat::ReturnHealth() / PlayerCombat::ReturnMaxHealth()) - (currentHealth / maxHealth) >= 0.50)
    {
        return MonsterDefend();
    }
    else if ((PlayerCombat::ReturnHealth() / PlayerCombat::ReturnMaxHealth()) - (currentHealth / maxHealth) >= 0.30)
    {
        if (isDefending)
        {
            return MonsterAttack(monsterDamage);
        }
    }

    return MonsterAttack(monsterDamage);
}

float Zombie::ReturnHealth() { return currentHealth; }

float Zombie::ReturnMaxHealth() { return maxHealth; }

string Zombie::ReturnName() { return name; }
#pragma endregion Zombie

#pragma region Spider
class Spider : public Monster // Erik - Inheritance
{
public:
    bool isDefending = false;
    static float maxHealth;
    static float currentHealth;
    float monsterDamage = 10;
    static string name;
    void SetHealth() override;
    float MonsterAttack(float monsterDamage) override;
    void TakeDamage(float damage) override;
    float MonsterDefend() override;
    float DetermineMove() override;
    float ReturnHealth() override;
    float ReturnMaxHealth() override;
    string ReturnName() override;
};

float Spider::maxHealth = 150;
float Spider::currentHealth = 150;
string Spider::name = "Spider";

void Spider::SetHealth()
{
    currentHealth = maxHealth;
}

void Spider::TakeDamage(float damage)
{
    if (isDefending) currentHealth -= damage / 3;
    else currentHealth -= damage;
}

float Spider::MonsterAttack(float monsterDamage)
{
    cout << "The " << name << " attacked and did " << monsterDamage << " damage!\n\n";
    isDefending = false;
    return monsterDamage;
}

float Spider::MonsterDefend()
{
    cout << "The " << name << " defended!\n\n";
    isDefending = true;
    return 0;
}

float Spider::DetermineMove()
{
    if ((PlayerCombat::ReturnHealth() / PlayerCombat::ReturnMaxHealth()) - (currentHealth / maxHealth) >= 0.50)
    {
        return MonsterDefend();
    }
    else if ((PlayerCombat::ReturnHealth() / PlayerCombat::ReturnMaxHealth()) - (currentHealth / maxHealth) >= 0.30)
    {
        if (isDefending)
        {
            return MonsterAttack(monsterDamage);
        }
    }

    return MonsterAttack(monsterDamage);
}

float Spider::ReturnHealth() { return currentHealth; }

float Spider::ReturnMaxHealth() { return maxHealth; }

string Spider::ReturnName() { return name; }
#pragma endregion Spider

#pragma region Skeleton
class Skeleton : public Monster // Erik - Inheritance
{
public:
    bool isDefending = false;
    static float maxHealth;
    static float currentHealth;
    float monsterDamage = 12;
    static string name;
    void SetHealth() override;
    float MonsterAttack(float monsterDamage) override;
    void TakeDamage(float damage) override;
    float MonsterDefend() override;
    float DetermineMove() override;
    float ReturnHealth() override;
    float ReturnMaxHealth() override;
    string ReturnName() override;
};

float Skeleton::maxHealth = 175;
float Skeleton::currentHealth = 175;
string Skeleton::name = "Skeleton";

void Skeleton::SetHealth()
{
    currentHealth = maxHealth;
}

void Skeleton::TakeDamage(float damage)
{
    if (isDefending) currentHealth -= damage / 3;
    else currentHealth -= damage;
}

float Skeleton::MonsterAttack(float monsterDamage)
{
    cout << "The " << name << " attacked and did " << monsterDamage << " damage!\n\n";
    isDefending = false;
    return monsterDamage;
}

float Skeleton::MonsterDefend()
{
    cout << "The " << name << " defended!\n\n";
    isDefending = true;
    return 0;
}

float Skeleton::DetermineMove()
{
    if ((PlayerCombat::ReturnHealth() / PlayerCombat::ReturnMaxHealth()) - (currentHealth / maxHealth) >= 0.50)
    {
        return MonsterDefend();
    }
    else if ((PlayerCombat::ReturnHealth() / PlayerCombat::ReturnMaxHealth()) - (currentHealth / maxHealth) >= 0.30)
    {
        if (isDefending)
        {
            return MonsterAttack(monsterDamage);
        }
    }

    return MonsterAttack(monsterDamage);
}

float Skeleton::ReturnHealth() { return currentHealth; }

float Skeleton::ReturnMaxHealth() { return maxHealth; }

string Skeleton::ReturnName() { return name; }
#pragma endregion Skeleton
#pragma endregion Monster

#pragma region Dialogue
class Dialogue // Will
{
public:
    string OutputDialogue(int dialogue);
    string OutputCombat(int combat, string monType);
private:
    string dialogue[100]; // The 100 is a placeholder
    string combatDialogue[20]; // 20 is too
    int dialogueLine = 0;
    int combatLine = 0;
};

string Dialogue::OutputDialogue(int dialogue) // Will
{
    string dialogueList[] = {
        "You are a wary adventurer who heard promise of treasures hidden deep within the cave you now find yourself in.",
        "The only light you have is a warm glow from a makeshift torch, and the only sound is the crackling of its fire, as it tries to naw its way through the piece of driftwood and cloth you fashioned it out of.",
        "The sound would be soothing if it weren't for the put in your stomach urging you, with every step, to turn heel and run.",
        "As you contemplate it an unfamiliar sound echoes from deep within the abyss in front of you.",
        "With the promise of treasure too good to pass up, you steel your nerves and press deeper into the darkness."
    };
   
    return dialogueList[dialogue];
}

string Dialogue::OutputCombat(int combat, string monType) // Will
{
    string dialogueList[] = {
        "A random " + monType + " appeared!",
        "What will you do?",
        "Invalid input! Please try something else. ",
        "You attack the " + monType + "!",
        "You heal yourself!",
        "The " +monType+ "attacks! Ouch!",
        "The " + monType + "is Defending!",
        "you defeated the "+ monType +"!",
        "You where slain by " +monType+ "! Game over!"
    };

    return dialogueList[combat];
}
#pragma endregion Dialogue


int main() // Erik
{
    string playerName;
    cout << "Insert Your Name:\n";
    cin >> playerName;
    cout << "\nWelcome " << playerName << "\n\n\n";

    PlayerCombat* player = new PlayerCombat();
    Monster* monsters[4];

    monsters[0] = new Slime();
    monsters[1] = new Zombie();
    monsters[2] = new Spider();
    monsters[3] = new Skeleton();

    int monInd = 0;

    while (PlayerCombat::ReturnHealth() > 0)
    {
        player->isDefending = false;

        cout << playerName << " HEALTH: " << PlayerCombat::ReturnHealth() << "/" << PlayerCombat::ReturnMaxHealth() << "\n";
        cout << monsters[monInd]->ReturnName() << " Health: " << monsters[monInd]->ReturnHealth() << " / " << monsters[monInd]->ReturnMaxHealth() << "\n";
        cout << "Actions:     Attack(1), Heal(2), Defend(3)\n";
        int action;
        cin >> action;
        switch (action) {
        case 1:
            //input enemy damage code
            monsters[monInd]->TakeDamage(player->damage);
            cout << playerName << " dealt " << player->damage << " damage to the enemy.";
            break;
        case 2:
            if (player->healTimer <= 0) {
                player->Heal();
                cout << playerName << " succesfully healed.";
            }
            else {
                cout << player->healTimer << " turns remain until the player can heal.";
            }
            break;
        case 3:
            player->isDefending = true;
            cout << playerName << " started to defend.";
            break;
        }

        player->TurnEnd();
        cout << "\n\n";

        if (monsters[monInd]->ReturnHealth() <= 0)
        {
            cout << "The " << monsters[monInd]->ReturnName() << " was defeated!\n\n";
            monsters[monInd]->SetHealth();
            monInd++;

            if (monInd == 4)
            {
                monInd = 0;
            }

            cout << "A " << monsters[monInd]->ReturnName() << " has appeared!\n\n";
        }
        else
        {
            player->TakeDamage(monsters[monInd]->DetermineMove());
        }
        cout << "\n\n\n\n\n\n"; //Keep this line at the end of all the code to make the output look more clear!
    }
}

// ---------- PLAYER COMBAT ---------
// The player combat will be a relatively simplistic style of combat system as it'll only contain a few actions that'll be possible
// for the player. The first action will be the "Attack" action which will subtract a set amount of health of the current enemy,
// and if time permits, I'd add a minimum and maximum possible damage that'll give a little variation to the gameplay. The next action
// that will be impletemented is the "Defend" action which will only allow 25% of the next enemy's damage through, blocking most
// but not all of the incoming damage. To do this, I'll divide the oncoming damage by 4. The last action is the "heal" action.
// This adds a set amount to your current health, if your current health exceeds your max health, it will be set to your max health.
// The heal action will also be put onto a turn cooldown so it can't be abused.
// The turn timer will function by having a set amount of turns before it can be used again. Each turn after the heal action is used
// The timer will tick down by 1 at the start of the player's turn. When it hits 0 the player can heal again.
// Lastly, at the start of the player's turn it will display their health and all the options the player can choose from.

// ---------- MONSTERS ----------
// Between rooms, the player will have to fight monsters. Later on we'll be implementing polymorphism to have a base monster class
// and then variants. The first and only public variable in the monster class so far is the function for taking damage. This will
// be called when the player attacks the monster. 
// The first private variable will be used to determine is the monster is defending when the player attacks.
// The next two private variables are for the monster's health and damage. They are pretty self explanatory; the former is 
// the monster's current health and the latter is how much damage is can do with an attack.
// We may introduce variation to its damage output too. Also, the monster doesn't keep track of max health since we don't plan for
// them to be able to heal.
// The DetermineMove function will be used to determine if the monster will attack or defend. To do so it'll look at its own health
// and the player's health. They will be used to determine the chance of the monster attacking. Then it'll use that chance to see
// which it does.
// The last two functions are self explanatory. The former will calculate the damage and send it to the player. The latter will
// Act as a buffer to reduce incoming damage next turn.

// ----------- DIALOGUE --------
// The dialogue system will be using arrays of strings to work. For the most part the game will be a linear experience. So we won't
// need to split up the dialogue too much unless we expand. The main dialogue will is dialogue array. Here we'll store the strings
// for the game between combat. The second array, combatDialogue, will hold strings for the different combat actions that are performed.
// The two variables below the arrays will be used to go through the corresponding arrays so that we can output the text.
// The two public functions will be called when needed such as when an attack is performed or the player is clicking through normal
// dialogue.