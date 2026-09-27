/**
 * CSE 3206 Software Engineering Sessional
 * Lab 3: Design Pattern Analysis, Implementation and Code Review
 * Group 2: Prototype Pattern Implementation
 *
 * Real-world Scenario: Game Character / Unit Spawning Engine (RTS/RPG)
 */

#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>
#include <vector>

// ==========================================
// 1. PROTOTYPE INTERFACE
// Declares the clone() method.
// ==========================================
class GameUnit {
public:
    virtual ~GameUnit() = default;
    
    // Core Prototype clone interface (pure virtual)
    virtual std::unique_ptr<GameUnit> clone() const = 0;
    
    // Presentation / gameplay method
    virtual void render(int unitId) const = 0;
    
    // Dynamic runtime customization
    virtual void setPosition(int x, int y) = 0;
    virtual void setCustomName(const std::string& name) = 0;
};

// ==========================================
// 2. CONCRETE PROTOTYPE 1: Swordsman / Warrior
// ==========================================
class Swordsman : public GameUnit {
private:
    std::string unitType;
    std::string customName;
    int health;
    int attackPower;
    int armor;
    std::string weapon;
    int posX = 0;
    int posY = 0;

public:
    Swordsman(const std::string& name, int hp, int atk, int def, const std::string& wpn)
        : unitType("Swordsman"), customName(name), health(hp), attackPower(atk), armor(def), weapon(wpn) {
        // Simulating expensive initialization (asset loading, audio preload, skill tree compilation)
    }

    // Copy constructor used for cloning
    Swordsman(const Swordsman& other)
        : unitType(other.unitType),
          customName(other.customName),
          health(other.health),
          attackPower(other.attackPower),
          armor(other.armor),
          weapon(other.weapon),
          posX(other.posX),
          posY(other.posY) {}

    // Implement clone() using copy constructor
    std::unique_ptr<GameUnit> clone() const override {
        return std::make_unique<Swordsman>(*this);
    }

    void setPosition(int x, int y) override {
        posX = x;
        posY = y;
    }

    void setCustomName(const std::string& name) override {
        customName = name;
    }

    void render(int unitId) const override {
        std::cout << "  [Unit #" << unitId << " - " << unitType << "] \"" << customName << "\"\n"
                  << "    Stats : HP=" << health << " | ATK=" << attackPower << " | ARMOR=" << armor << "\n"
                  << "    Weapon: " << weapon << "\n"
                  << "    Coord : (" << posX << ", " << posY << ")\n\n";
    }
};

// ==========================================
// 3. CONCRETE PROTOTYPE 2: Archer
// ==========================================
class Archer : public GameUnit {
private:
    std::string unitType;
    std::string customName;
    int health;
    int attackRange;
    int agility;
    std::string bowType;
    int posX = 0;
    int posY = 0;

public:
    Archer(const std::string& name, int hp, int range, int agi, const std::string& bow)
        : unitType("Archer"), customName(name), health(hp), attackRange(range), agility(agi), bowType(bow) {}

    Archer(const Archer& other)
        : unitType(other.unitType),
          customName(other.customName),
          health(other.health),
          attackRange(other.attackRange),
          agility(other.agility),
          bowType(other.bowType),
          posX(other.posX),
          posY(other.posY) {}

    std::unique_ptr<GameUnit> clone() const override {
        return std::make_unique<Archer>(*this);
    }

    void setPosition(int x, int y) override {
        posX = x;
        posY = y;
    }

    void setCustomName(const std::string& name) override {
        customName = name;
    }

    void render(int unitId) const override {
        std::cout << "  [Unit #" << unitId << " - " << unitType << "] \"" << customName << "\"\n"
                  << "    Stats : HP=" << health << " | RANGE=" << attackRange << " | AGILITY=" << agility << "\n"
                  << "    Weapon: " << bowType << "\n"
                  << "    Coord : (" << posX << ", " << posY << ")\n\n";
    }
};

// ==========================================
// 4. CONCRETE PROTOTYPE 3: Mage / Sorcerer
// ==========================================
class Mage : public GameUnit {
private:
    std::string unitType;
    std::string customName;
    int health;
    int mana;
    std::string spellElement;
    std::string staffType;
    int posX = 0;
    int posY = 0;

public:
    Mage(const std::string& name, int hp, int mp, const std::string& element, const std::string& staff)
        : unitType("Mage"), customName(name), health(hp), mana(mp), spellElement(element), staffType(staff) {}

    Mage(const Mage& other)
        : unitType(other.unitType),
          customName(other.customName),
          health(other.health),
          mana(other.mana),
          spellElement(other.spellElement),
          staffType(other.staffType),
          posX(other.posX),
          posY(other.posY) {}

    std::unique_ptr<GameUnit> clone() const override {
        return std::make_unique<Mage>(*this);
    }

    void setPosition(int x, int y) override {
        posX = x;
        posY = y;
    }

    void setCustomName(const std::string& name) override {
        customName = name;
    }

    void render(int unitId) const override {
        std::cout << "  [Unit #" << unitId << " - " << unitType << "] \"" << customName << "\"\n"
                  << "    Stats : HP=" << health << " | MANA=" << mana << " | ELEMENT=" << spellElement << "\n"
                  << "    Weapon: " << staffType << "\n"
                  << "    Coord : (" << posX << ", " << posY << ")\n\n";
    }
};

// ==========================================
// 5. PROTOTYPE REGISTRY / SPAWN MANAGER
// Caches master prototypes and clones them on demand.
// ==========================================
class UnitRegistry {
private:
    std::unordered_map<std::string, std::unique_ptr<GameUnit>> prototypes;

public:
    void registerPrototype(const std::string& key, std::unique_ptr<GameUnit> prototype) {
        prototypes[key] = std::move(prototype);
    }

    // Creates a new unit instance by cloning the registered prototype
    std::unique_ptr<GameUnit> spawnUnit(const std::string& key) const {
        auto it = prototypes.find(key);
        if (it != prototypes.end()) {
            return it->second->clone(); // Returns deep cloned copy
        }
        std::cerr << "Error: Prototype with key '" << key << "' not registered!\n";
        return nullptr;
    }
};

// ==========================================
// 6. CLIENT CODE (main)
// Demonstrates fast spawning via cloning.
// ==========================================
int main() {
    std::cout << "========================================================\n";
    std::cout << "      CSE 3206 LAB 3 - PROTOTYPE PATTERN DEMO          \n";
    std::cout << "========================================================\n\n";

    // 1. Initializing and Registering Master Prototypes in Registry
    std::cout << "[Step 1] Loading and caching master unit prototypes...\n";
    UnitRegistry registry;

    registry.registerPrototype(
        "elite_swordsman",
        std::make_unique<Swordsman>("Royal Guard", 150, 45, 30, "Excalibur Greatsword")
    );

    registry.registerPrototype(
        "sniper_archer",
        std::make_unique<Archer>("Elven Marksman", 90, 80, 70, "Windrunner Longbow")
    );

    registry.registerPrototype(
        "pyro_mage",
        std::make_unique<Mage>("Archmage", 80, 200, "Firestorm", "Phoenix Staff")
    );

    std::cout << "Master prototypes successfully registered in memory.\n\n";

    // 2. Spawning Army Squad via Fast Cloning
    std::cout << "[Step 2] Spawning units on battlefield via Prototype cloning:\n";
    std::cout << "--------------------------------------------------------\n";

    std::vector<std::unique_ptr<GameUnit>> battlefieldArmy;

    // Clone 2 Swordsmen
    auto s1 = registry.spawnUnit("elite_swordsman");
    s1->setPosition(10, 20);
    s1->setCustomName("Vanguard Arthur");
    battlefieldArmy.push_back(std::move(s1));

    auto s2 = registry.spawnUnit("elite_swordsman");
    s2->setPosition(12, 22);
    s2->setCustomName("Vanguard Lancelot");
    battlefieldArmy.push_back(std::move(s2));

    // Clone 2 Archers
    auto a1 = registry.spawnUnit("sniper_archer");
    a1->setPosition(5, 50);
    a1->setCustomName("Scout Robin");
    battlefieldArmy.push_back(std::move(a1));

    auto a2 = registry.spawnUnit("sniper_archer");
    a2->setPosition(8, 52);
    a2->setCustomName("Scout Legolas");
    battlefieldArmy.push_back(std::move(a2));

    // Clone 1 Mage
    auto m1 = registry.spawnUnit("pyro_mage");
    m1->setPosition(2, 15);
    m1->setCustomName("Grand Wizard Gandalf");
    battlefieldArmy.push_back(std::move(m1));

    // 3. Render all deployed units
    int unitId = 1;
    for (const auto& unit : battlefieldArmy) {
        unit->render(unitId++);
    }

    std::cout << "--------------------------------------------------------\n";
    std::cout << "Prototype Pattern demonstration executed successfully.\n";
    std::cout << "Notice: All 5 units were instantiated via zero-overhead\n";
    std::cout << "cloning without repeating expensive initialization logic!\n";

    return 0;
}
