#include "Graph.hpp"
#include "Vector2.hpp"
#include <iostream>

void printSection(const std::string& title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "========================================" << std::endl;
}

void testBasicGraph() {
    printSection("TEST 1: Basic Graph");
    Graph graph(6, 6);
    
    std::cout << "Adding valid points..." << std::endl;
    graph.addVector(0, 0);
    graph.addVector(2, 2);
    graph.addVector(4, 2);
    graph.addVector(2, 4);
    
    graph.display();
}

void testOutOfBounds() {
    printSection("TEST 2: Out of Bounds");
    Graph graph(6, 6);
    
    std::cout << "Testing negative X: (-1, 2)" << std::endl;
    graph.addVector(-1, 2);
    
    std::cout << "\nTesting negative Y: (2, -1)" << std::endl;
    graph.addVector(2, -1);
    
    std::cout << "\nTesting X >= width: (6, 2)" << std::endl;
    graph.addVector(6, 2);
    
    std::cout << "\nTesting Y >= height: (2, 6)" << std::endl;
    graph.addVector(2, 6);
    
    std::cout << "\nTesting both out: (10, 10)" << std::endl;
    graph.addVector(10, 10);
    
    graph.display();
}

void testCorners() {
    printSection("TEST 3: Corner Points");
    Graph graph(5, 5);
    
    std::cout << "Testing all 4 corners..." << std::endl;
    graph.addVector(0, 0);        
    graph.addVector(4, 0);        
    graph.addVector(0, 4);
    graph.addVector(4, 4);
    
    graph.display();
}

// Tests troncature float
void testFloatTruncation() {
    printSection("TEST 4: Float Truncation");
    Graph graph(6, 6);
    
    std::cout << "Adding (2.1, 3.1) - should appear at (2, 3)" << std::endl;
    graph.addVector(2.1f, 3.1f);
    
    std::cout << "Adding (2.9, 3.9) - should appear at (2, 3)" << std::endl;
    graph.addVector(2.9f, 3.9f);
    
    std::cout << "Adding (0.5, 0.5) - should appear at (0, 0)" << std::endl;
    graph.addVector(0.5f, 0.5f);
    
    graph.display();
}

// Tests points identiques
void testDuplicatePoints() {
    printSection("TEST 5: Duplicate Points");
    Graph graph(5, 5);
    
    std::cout << "Adding (2, 2) first time" << std::endl;
    graph.addVector(2, 2);
    
    std::cout << "Adding (2, 2) second time" << std::endl;
    graph.addVector(2, 2);
    
    graph.display();
}

// Tests graphique petit
void testSmallGraph() {
    printSection("TEST 6: Very Small Graph");
    Graph graph(2, 2);
    
    std::cout << "Graph 2x2 with point (1, 1)" << std::endl;
    graph.addVector(1, 1);
    
    graph.display();
}

// Tests graphique vide
void testEmptyGraph() {
    printSection("TEST 7: Empty Graph");
    Graph graph(4, 4);
    
    std::cout << "Graph with no points" << std::endl;
    graph.display();
}

// Tests beaucoup de points
void testManyPoints() {
    printSection("TEST 8: Many Points");
    Graph graph(10, 10);
    
    std::cout << "Adding 20 points..." << std::endl;
    for (int i = 0; i < 20; i++) {
        graph.addVector(i % 10, i / 2);
    }
    
    graph.display();
}


int main() {
    std::cout << "╔══════════════════════════════════════╗" << std::endl;
    std::cout << "║    GRAPH TEST                        ║" << std::endl;
    std::cout << "╚══════════════════════════════════════╝" << std::endl;
    
    testBasicGraph();
    testOutOfBounds();
    testCorners();
    testFloatTruncation();
    testDuplicatePoints();
    testSmallGraph();
    testEmptyGraph();
    testManyPoints();
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "ALL TESTS COMPLETED" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    return 0;
}