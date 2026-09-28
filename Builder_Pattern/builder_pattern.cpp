/**
 * CSE 3206 Software Engineering Sessional
 * Lab 3: Design Pattern Analysis, Implementation and Code Review
 * Group 2: Builder Pattern Implementation
 *
 * Real-world Scenario: Custom Desktop Computer Assembly System
 */

#include <iostream>
#include <string>
#include <memory>
#include <iomanip>

// ==========================================
// 1. PRODUCT
// The complex object under construction.
// ==========================================
class Computer {
private:
    std::string cpu;
    std::string motherboard;
    std::string ram;
    std::string storage;
    std::string gpu;
    std::string powerSupply;
    std::string cooling;
    bool hasWifiCard = false;

public:
    // Setters used by the Builder
    void setCPU(const std::string& val) { cpu = val; }
    void setMotherboard(const std::string& val) { motherboard = val; }
    void setRAM(const std::string& val) { ram = val; }
    void setStorage(const std::string& val) { storage = val; }
    void setGPU(const std::string& val) { gpu = val; }
    void setPowerSupply(const std::string& val) { powerSupply = val; }
    void setCooling(const std::string& val) { cooling = val; }
    void setWifi(bool val) { hasWifiCard = val; }

    void displaySpecifications() const {
        std::cout << "--------------------------------------------------\n";
        std::cout << "             COMPUTER SPECIFICATIONS              \n";
        std::cout << "--------------------------------------------------\n";
        std::cout << "  Motherboard : " << motherboard << "\n";
        std::cout << "  Processor   : " << cpu << "\n";
        std::cout << "  RAM         : " << ram << "\n";
        std::cout << "  Storage     : " << storage << "\n";
        std::cout << "  Graphics    : " << gpu << "\n";
        std::cout << "  Power Supply: " << powerSupply << "\n";
        std::cout << "  Cooling     : " << cooling << "\n";
        std::cout << "  Wi-Fi Card  : " << (hasWifiCard ? "Installed" : "None") << "\n";
        std::cout << "--------------------------------------------------\n\n";
    }
};

// ==========================================
// 2. BUILDER INTERFACE
// Declares step-by-step construction methods.
// ==========================================
class ComputerBuilder {
public:
    virtual ~ComputerBuilder() = default;
    virtual void reset() = 0;
    virtual void buildMotherboard() = 0;
    virtual void buildCPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;
    virtual void buildGPU() = 0;
    virtual void buildPowerSupply() = 0;
    virtual void buildCooling() = 0;
    virtual void buildNetwork() = 0;
    virtual std::unique_ptr<Computer> getResult() = 0;
};

// ==========================================
// 3. CONCRETE BUILDER 1: Gaming PC Builder
// High-performance dedicated components.
// ==========================================
class GamingComputerBuilder : public ComputerBuilder {
private:
    std::unique_ptr<Computer> computer;

public:
    GamingComputerBuilder() { reset(); }

    void reset() override {
        computer = std::make_unique<Computer>();
    }

    void buildMotherboard() override {
        computer->setMotherboard("ASUS ROG Maximus Z790 Hero");
    }

    void buildCPU() override {
        computer->setCPU("Intel Core i9-14900K (24 cores, 6.0 GHz)");
    }

    void buildRAM() override {
        computer->setRAM("64 GB (2 x 32GB) DDR5-6000 MHz RGB");
    }

    void buildStorage() override {
        computer->setStorage("2 TB Samsung 990 PRO NVMe PCIe 4.0 SSD");
    }

    void buildGPU() override {
        computer->setGPU("NVIDIA GeForce RTX 4090 24GB GDDR6X");
    }

    void buildPowerSupply() override {
        computer->setPowerSupply("Corsair RM1000x 1000W 80+ Gold Fully Modular");
    }

    void buildCooling() override {
        computer->setCooling("NZXT Kraken Elite 360 RGB Liquid Cooler");
    }

    void buildNetwork() override {
        computer->setWifi(true);
    }

    std::unique_ptr<Computer> getResult() override {
        std::unique_ptr<Computer> result = std::move(computer);
        reset(); // Reset builder for next construction
        return result;
    }
};

// ==========================================
// 4. CONCRETE BUILDER 2: Office PC Builder
// Cost-effective, reliable business setup.
// ==========================================
class OfficeComputerBuilder : public ComputerBuilder {
private:
    std::unique_ptr<Computer> computer;

public:
    OfficeComputerBuilder() { reset(); }

    void reset() override {
        computer = std::make_unique<Computer>();
    }

    void buildMotherboard() override {
        computer->setMotherboard("MSI PRO B760M-A WiFi DDR4");
    }

    void buildCPU() override {
        computer->setCPU("Intel Core i5-13400 (10 cores, 4.6 GHz)");
    }

    void buildRAM() override {
        computer->setRAM("16 GB (2 x 8GB) DDR4-3200 MHz");
    }

    void buildStorage() override {
        computer->setStorage("512 GB Kingston NV2 PCIe 4.0 NVMe SSD");
    }

    void buildGPU() override {
        computer->setGPU("Integrated Intel UHD Graphics 730");
    }

    void buildPowerSupply() override {
        computer->setPowerSupply("Corsair CV550 550W 80+ Bronze");
    }

    void buildCooling() override {
        computer->setCooling("Intel Stock Air Cooler");
    }

    void buildNetwork() override {
        computer->setWifi(true);
    }

    std::unique_ptr<Computer> getResult() override {
        std::unique_ptr<Computer> result = std::move(computer);
        reset();
        return result;
    }
};

// ==========================================
// 5. DIRECTOR
// Defines the sequence of construction steps.
// ==========================================
class ComputerAssembler {
private:
    ComputerBuilder* builder;

public:
    void setBuilder(ComputerBuilder* b) {
        builder = b;
    }

    // Construct a complete standard configuration
    void constructFullPC() {
        if (!builder) return;
        builder->reset();
        builder->buildMotherboard();
        builder->buildCPU();
        builder->buildRAM();
        builder->buildStorage();
        builder->buildGPU();
        builder->buildPowerSupply();
        builder->buildCooling();
        builder->buildNetwork();
    }

    // Construct a minimal budget/headless server configuration
    void constructMinimalPC() {
        if (!builder) return;
        builder->reset();
        builder->buildMotherboard();
        builder->buildCPU();
        builder->buildRAM();
        builder->buildStorage();
        builder->buildPowerSupply();
    }
};

// ==========================================
// 6. CLIENT CODE (main)
// Demonstrates how client interacts with Director & Builders.
// ==========================================
int main() {
    std::cout << "========================================================\n";
    std::cout << "       CSE 3206 LAB 3 - BUILDER PATTERN DEMO           \n";
    std::cout << "========================================================\n\n";

    ComputerAssembler assembler;

    // 1. Building a High-End Gaming PC via Director
    std::cout << "[Step 1] Assembling High-End Gaming PC via Director...\n";
    GamingComputerBuilder gamingBuilder;
    assembler.setBuilder(&gamingBuilder);
    assembler.constructFullPC();
    std::unique_ptr<Computer> gamingPC = gamingBuilder.getResult();
    gamingPC->displaySpecifications();

    // 2. Building a Standard Office PC via Director
    std::cout << "[Step 2] Assembling Standard Office Workstation via Director...\n";
    OfficeComputerBuilder officeBuilder;
    assembler.setBuilder(&officeBuilder);
    assembler.constructFullPC();
    std::unique_ptr<Computer> officePC = officeBuilder.getResult();
    officePC->displaySpecifications();

    // 3. Custom assembly without Director (Client directly driving Builder)
    std::cout << "[Step 3] Custom Customization: Assembling Custom Barebones Server...\n";
    officeBuilder.reset();
    officeBuilder.buildMotherboard();
    officeBuilder.buildCPU();
    officeBuilder.buildRAM();
    officeBuilder.buildStorage();
    officeBuilder.buildPowerSupply();
    // Intentionally skipped GPU, RGB cooling, Wi-Fi card
    std::unique_ptr<Computer> customServer = officeBuilder.getResult();
    customServer->displaySpecifications();

    std::cout << "Builder Pattern demonstration executed successfully.\n";
    return 0;
}
