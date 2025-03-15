// CPPAssignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main() // Erik
{
    
}

#pragma region Player
class PlayerCombat // Sophie
{
public:
    float damage;
    float healAmount;
    float ReturnHealth();
    void TakeDamage(float damage);
private:
    float currentHealth;
    float maxHealth;
    int healTimer = 3;
    int healTimerTurnAmount = 3;
    void Heal(float healAmount);
};

float PlayerCombat::ReturnHealth() // Sophie
{
    return currentHealth;
}

void PlayerCombat::TakeDamage(float damage) // Sophie
{

}

void PlayerCombat::Heal(float healAmount) // Sophie
{

}
#pragma endregion Player

#pragma region Monster
class Monster // Erik
{
public:
    void TakeDamage(float damage);
private:
    bool isDefending = false;
    float monsterHealth;
    float monsterDamage;
    void DetermineMove();
    void MonsterAttack();
    void MonsterDefend();
};

void Monster::DetermineMove() // Erik
{
    
}

void Monster::MonsterAttack() // Erik
{

}

void Monster::MonsterDefend() // Erik
{

}

void Monster::TakeDamage(float damage) // Erik
{

}
#pragma endregion Monster

#pragma region Dialogue
class Dialogue // Will
{
public:
    string OutputDialogue(int dialogue);
    string OutputCombat(int combat);
private:
    string dialogue[100]; // The 100 is a placeholder
    string combatDialogue[20]; // 20 is too
    int dialogueLine = 0;
    int combatLine = 0;
};

string Dialogue::OutputDialogue(int dialogue) // Will
{

}

string Dialogue::OutputCombat(int combat) // Will
{

}
#pragma endregion Dialogue

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