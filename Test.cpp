#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "card.hpp"
#include "game.hpp"
#include "player.hpp"
using namespace ariel;
/*TEST_CASE("Card class test") {
    const Card card1(Card::HEARTS, Card::ACE);
    const Card card2(Card::DIAMONDS, Card::KING);
    const Card card3(Card::SPADES, Card::QUEEN);
    const Card card4(Card::CLUBS, Card::JACK);
    const Card card5(Card::HEARTS, Card::TEN);
    const Card card6(Card::DIAMONDS, Card::NINE);
    const Card card7(Card::SPADES, Card::EIGHT);
    const Card card8(Card::CLUBS, Card::SEVEN);
    const Card card9(Card::HEARTS, Card::SIX);
    const Card card10(Card::DIAMONDS, Card::FIVE);
    SUBCASE("Card initialization tests") {
        CHECK((card1.get_suit() == Card::HEARTS));
        CHECK((card1.get_value() == Card::ACE));

        CHECK((card2.get_suit() == Card::DIAMONDS));
        CHECK((card2.get_value() == Card::KING));

        CHECK((card3.get_suit() == Card::SPADES));
        CHECK((card3.get_value() == Card::QUEEN));

        CHECK((card4.get_suit() == Card::CLUBS));
        CHECK((card4.get_value() == Card::JACK));

        CHECK((card5.get_suit() == Card::HEARTS));
        CHECK((card5.get_value() == Card::TEN));

        CHECK((card6.get_suit() == Card::DIAMONDS));
        CHECK((card6.get_value() == Card::NINE));

        CHECK((card7.get_suit() == Card::SPADES));
        CHECK((card7.get_value() == Card::EIGHT));

        CHECK((card8.get_suit() == Card::CLUBS));
        CHECK((card8.get_value() == Card::SEVEN));

        CHECK((card9.get_suit() == Card::HEARTS));
        CHECK((card9.get_value() == Card::SIX));

        CHECK((card10.get_suit() == Card::DIAMONDS));
        CHECK((card10.get_value() == Card::FIVE));
    }

    SUBCASE("Card class copy constructor test") {
        Card card_copy{card1};
        CHECK((card_copy.get_suit() == Card::HEARTS));
        CHECK((card_copy.get_value() == Card::ACE));
        CHECK((card_copy == card1));

        Card copy_card2{card2};
        CHECK((copy_card2.get_suit() == card2.get_suit()));
        CHECK((copy_card2.get_value() == card2.get_value()));
    }

    SUBCASE("Card class < operator tests") {
        CHECK((card1 < card2));
        CHECK_FALSE((card4 < card5));
        CHECK((card4 < card2));
        CHECK_FALSE((card2 < card6));
    }
    SUBCASE("Card class > operator tests") {
        CHECK((card6 > card7));
        CHECK_FALSE((card8 > card9));
        CHECK((card9 > card10));
        CHECK_FALSE((card10 > card2));
    }

    SUBCASE("Card class boundary tests") {
        Card card_low(Card::HEARTS, Card::ACE);
        Card card_high(Card::HEARTS, Card::KING);

        CHECK((card_low < card_high));
        CHECK_FALSE((card_low > card_high));
        CHECK_FALSE((card_low == card_high));
    }

    SUBCASE("Card class == operator tests") {
        Card temp{Card::SPADES, Card::ACE};
        CHECK((card1 == temp));

        Card temp2 = {Card::CLUBS, Card::KING};
        CHECK((temp2 == card2));

        Card temp3{Card::DIAMONDS, Card::QUEEN};
        CHECK((temp3 == card3));

        Card card11(Card::HEARTS, Card::ACE);
        CHECK((card1 == card11));

        CHECK_FALSE((card1 == card2));
        CHECK_FALSE((card3 == card4));
    }

    SUBCASE("Card class get_value() function tests") {
        CHECK((card10.get_value() == Card::FIVE));
        CHECK((card9.get_value() == Card::SIX));
        CHECK((card8.get_value() == Card::SEVEN));
        CHECK((card7.get_value() == Card::EIGHT));
        CHECK((card6.get_value() == Card::NINE));
        CHECK((card5.get_value() == Card::TEN));
        CHECK_FALSE((card4.get_value() == Card::QUEEN));
        CHECK_FALSE((card3.get_value() == Card::JACK));
        CHECK_FALSE((card2.get_value() == Card::ACE));
        CHECK_FALSE((card1.get_value() == Card::KING));

    }

    SUBCASE("Card class get_suit() function test") {
        CHECK((card1.get_suit() == Card::HEARTS));
        CHECK((card2.get_suit() == Card::DIAMONDS));
        CHECK((card3.get_suit() == Card::SPADES));
        CHECK((card4.get_suit() == Card::CLUBS));
        CHECK_FALSE((card5.get_suit() == Card::CLUBS));
        CHECK_FALSE((card6.get_suit() == Card::SPADES));
        CHECK_FALSE((card7.get_suit() == Card::DIAMONDS));
        CHECK_FALSE((card8.get_suit() == Card::HEARTS));
    }

    SUBCASE("Card class invalid input test") {
        // Test case for invalid Suit values
        CHECK_THROWS(Card(static_cast<Card::Suit>(-1), Card::ACE));
        CHECK_THROWS(Card(static_cast<Card::Suit>(4), Card::ACE));

        // Test case for invalid Rank values
        CHECK_THROWS(Card(Card::HEARTS, static_cast<Card::Rank>(0)));
        CHECK_THROWS(Card(Card::HEARTS, static_cast<Card::Rank>(14)));
    }
}*/

TEST_CASE("Player class tests") {

    SUBCASE("Player Default constructor test") {
        Player p{};
        CHECK((p.get_name() == "No Name"));
        CHECK((p.cardesTaken() == 0));
        CHECK((p.stacksize() == 0));
    }

    SUBCASE("Player arg constructor test") {
        Player p{"Amit"};
        CHECK((p.get_name() == "Amit"));
        CHECK((p.cardesTaken() == 0));
        CHECK((p.stacksize() == 0));
    }

    SUBCASE("Player get_name() function tests") {
        Player p{"Amit Raz"};
        CHECK((p.get_name() == "Amit Raz"));
        Player p1{""};
        CHECK((p1.get_name() == ""));
    }

    SUBCASE("Player stacksize() function tests") {
        Player p{"Amit"};
        CHECK((p.stacksize() == 0)); // empty stack

        Card card1(Card::HEARTS, Card::ACE);
        Card card2(Card::DIAMONDS, Card::KING);
        Card card3(Card::SPADES, Card::QUEEN);

        p.addcard(card1);
        CHECK((p.stacksize() == 1));

        p.addcard(card2);
        CHECK((p.stacksize() == 2));

        p.addcard(card3);
        CHECK((p.stacksize() == 3));

        p.removecard();
        CHECK((p.stacksize() == 2));

        p.removecard();
        CHECK((p.stacksize() == 1));

        p.removecard();
        CHECK((p.stacksize() == 0));
    }

    SUBCASE("Player cardesTaken with won tests") {
        Player p{};

        for (int i = 0; i < 53; i++) {
            CHECK((p.cardesTaken() == i));
            p.won(1);
        }

        Player p2{};
        p.won(10);
        CHECK((p.cardesTaken() == 10));
    }

    SUBCASE("Player won() function tests") {
        Player p{};
        CHECK_THROWS(p.won(-1));
        CHECK_THROWS(p.won(53));
        CHECK_NOTHROW(p.won(52));
        CHECK_THROWS(p.won(0));

    }
    SUBCASE("Player removecard() function and topCard() tests") {
        Player p{};

        Card card1(Card::HEARTS, Card::ACE);
        Card card2(Card::DIAMONDS, Card::KING);
        Card card3(Card::SPADES, Card::QUEEN);
        Card card4(Card::CLUBS, Card::JACK);
        p.addcard(card1);
        p.addcard(card2);
        p.addcard(card3);
        p.addcard(card4);

        CHECK((p.topCard().get_value() == card4.get_value()));
        CHECK((p.topCard().get_suit() == card4.get_suit()));
        p.removecard();
        CHECK((p.stacksize() == 3));
        CHECK((p.topCard().get_value() == card3.get_value()));
        CHECK((p.topCard().get_suit() == card3.get_suit()));
        p.removecard();
        CHECK((p.stacksize() == 2));
        CHECK((p.topCard().get_value() == card2.get_value()));
        CHECK((p.topCard().get_suit() == card2.get_suit()));
        p.removecard();
        CHECK((p.stacksize() == 1));
        CHECK((p.topCard().get_value() == card1.get_value()));
        CHECK((p.topCard().get_suit() == card1.get_suit()));
        p.removecard();
        CHECK((p.stacksize() == 0));
        CHECK_THROWS(((p.removecard())));
    }

    SUBCASE("Player addcard() function tests") {
        Player p{"Amit"};

        for (int suit = Card::HEARTS; suit <= Card::SPADES; ++suit) {
            for (int rank = Card::ACE; rank <= Card::KING; ++rank) {
                Card card(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank));
                p.addcard(card);
            }
        }

        CHECK((p.stacksize() == 52));

        Card extraCard(Card::HEARTS, Card::ACE);
        CHECK_THROWS((p.addcard(extraCard)));
    }
}

TEST_CASE("Game class tests") {
    Player p1("Alice");
    Player p2("Bob");

    auto create_new_game = [&]() {
        return Game(p1, p2);
    };

    SUBCASE("Game handles cards distribution correctly") {


        Game g = create_new_game();
        CHECK((p1.stacksize() == 26 && p2.stacksize() == 26));
        CHECK((p1.cardesTaken() == 0 && p2.cardesTaken() == 0));
    }

    SUBCASE("Testing stacksize and cardedTaken updates correctly after a single round") {
        Game g = create_new_game();

        // Save initial stack sizes and cards won
        int initialStackSize_p1 = p1.stacksize();
        int initialStackSize_p2 = p2.stacksize();
        int initialCardsTaken_p1 = p1.cardesTaken();
        int initialCardsTaken_p2 = p2.cardesTaken();

            g.playTurn();


        // Check that the sum of cards won and stack sizes for both players remains constant
        int totalCards_p1 = p1.stacksize() + p1.cardesTaken();
        int totalCards_p2 = p2.stacksize() + p2.cardesTaken();

        CHECK((totalCards_p1 + totalCards_p2 == initialStackSize_p1 + initialStackSize_p2 + initialCardsTaken_p1 + initialCardsTaken_p2));
    }


    SUBCASE("Testing stacksize and cardedTaken updates correctly after 5 rounds") {
        Game g = create_new_game();

        // Save initial stack sizes and cards won
        int initialStackSize_p1 = p1.stacksize();
        int initialStackSize_p2 = p2.stacksize();
        int initialCardsTaken_p1 = p1.cardesTaken();
        int initialCardsTaken_p2 = p2.cardesTaken();

        for (int i = 0; i < 5; i++) {
            g.playTurn();
        }

        // Check that the sum of cards won and stack sizes for both players remains constant
        int totalCards_p1 = p1.stacksize() + p1.cardesTaken();
        int totalCards_p2 = p2.stacksize() + p2.cardesTaken();

        CHECK((totalCards_p1 + totalCards_p2 == initialStackSize_p1 + initialStackSize_p2 + initialCardsTaken_p1 + initialCardsTaken_p2));
    }

    SUBCASE("Testing stacksize and cardedTaken updates correctly after 10 rounds") {
        Game g = create_new_game();

        // Save initial stack sizes and cards won
        int initialStackSize_p1 = p1.stacksize();
        int initialStackSize_p2 = p2.stacksize();
        int initialCardsTaken_p1 = p1.cardesTaken();
        int initialCardsTaken_p2 = p2.cardesTaken();

        for (int i = 0; i < 10; i++) {
            g.playTurn();
        }

        // Check that the sum of cards won and stack sizes for both players remains constant
        int totalCards_p1 = p1.stacksize() + p1.cardesTaken();
        int totalCards_p2 = p2.stacksize() + p2.cardesTaken();

        CHECK((totalCards_p1 + totalCards_p2 == initialStackSize_p1 + initialStackSize_p2 + initialCardsTaken_p1 + initialCardsTaken_p2));
    }


    SUBCASE("Test playAll() function") {
        Game g = create_new_game();

        g.playAll();


        CHECK((p1.stacksize() == 0 && p2.stacksize() == 0));
        CHECK(((p1.cardesTaken()+p2.cardesTaken()) == 52));
    }

    SUBCASE("Test playTurn() doesn't throw an exception when the game is finished") {
        Game g = create_new_game();

        g.playAll();
        for (int i = 0; i < 5; i++) {
            CHECK_NOTHROW(g.playTurn());
        }
    }

    SUBCASE("Test playAll() works correctly when calling after a few round") {
        Game g = create_new_game();

        for (int i = 0; i < 10; i++) {
            g.playTurn();
        }

        g.playAll();

        bool gameFinished =
                (p1.stacksize() == 0 && p2.cardesTaken() == 52) || (p2.stacksize() == 0 && p1.cardesTaken() == 52);
        CHECK(gameFinished);
    }

    SUBCASE("Test multiple calls to playAll()") {
        Game g = create_new_game();

        g.playAll();
        // Game should already be finished after the first playAll, and any subsequent calls to playAll should have no effect
        CHECK_NOTHROW(g.playAll());
        bool game_finished =
                (p1.stacksize() == 0 && p2.cardesTaken() == 52) || (p2.stacksize() == 0 && p1.cardesTaken() == 52);
        CHECK(game_finished);
    }

    SUBCASE("Test calling playTurn() after playAll()") {
        Game g = create_new_game();

        g.playAll();
        // Game should already be finished after playAll, and any subsequent calls to playTurn should have no effect
        CHECK_NOTHROW(g.playTurn());
        bool game_finished =
                (p1.stacksize() == 0 && p2.cardesTaken() == 52) || (p2.stacksize() == 0 && p1.cardesTaken() == 52);
        CHECK(game_finished);
    }
    SUBCASE("Card count consistency") {
        Game g = create_new_game();

        int turns = 10;
        for (int i = 0; i < turns; i++) {
            g.playTurn();
        }

        int total_cards = p1.stacksize() + p2.stacksize() + p1.cardesTaken() + p2.cardesTaken();
        CHECK((total_cards == 52));
    }
    SUBCASE("Sum of cards won is proportional to the number of turns played") {
        Game game = create_new_game();

        int turnsPlayed = 10;
        for (int i = 0; i < turnsPlayed; i++) {
            game.playTurn();
        }

        int totalCardsWon = p1.cardesTaken() + p2.cardesTaken();

        CHECK((turnsPlayed <= totalCardsWon)); // <= because of potential draws
    }

    SUBCASE("Test player registration to a second game while already playing in an unfinished game"){
        Game game1 = create_new_game();
        Player p3 {"Amit"};
        CHECK_THROWS_AS(Game game2(p1, p3), std::invalid_argument);
        CHECK_THROWS_AS(Game game2(p3, p1), std::invalid_argument);
    }

    SUBCASE("Players names are printed in printLastTurn") {
        Game g = create_new_game();

        g.playTurn();

        // Redirect standard output stream to a stringstream
        std::stringstream last_turn_output;
        auto original_cout_buf = std::cout.rdbuf(last_turn_output.rdbuf());

        // Call printLastTurn()
        g.printLastTurn();

        // Restore the original standard output stream
        std::cout.rdbuf(original_cout_buf);

        // Check if the output contains the player names
        CHECK((last_turn_output.str().find("Alice") != std::string::npos));
        CHECK((last_turn_output.str().find("Bob") != std::string::npos));
    }

    SUBCASE("Test printLastTurn function") {
        Game g = create_new_game();

        // Save initial cards won
        int initialCardsTaken_p1 = p1.cardesTaken();
        int initialCardsTaken_p2 = p2.cardesTaken();

        g.playTurn();

        int newCardsTaken_p1 = p1.cardesTaken();
        int newCardsTaken_p2 = p2.cardesTaken();

        std::stringstream ss;
        std::streambuf* old_buf = std::cout.rdbuf(ss.rdbuf()); // Redirect stdout to the stringstream

        g.printLastTurn();

        std::cout.rdbuf(old_buf); // Restore the original stdout buffer

        std::string output = ss.str();

        if (newCardsTaken_p1 > initialCardsTaken_p1) {
            // Player 1 won the last round
            std::string expected_substring = "Alice wins";
            CHECK((output.find(expected_substring) != std::string::npos));
        } else{
            // Player 2 won the last round
            std::string expected_substring = "Bob wins";
            CHECK((output.find(expected_substring) != std::string::npos));
        }
    }
    // Test printLog line count and uniqueness
    SUBCASE("Test printLog print the correct number of lines and unique lines") {
        Game game = create_new_game();
        int turns = 5;
        for (int i = 0; i < turns; i++) {
            game.playTurn();
        }

        // Redirect standard output stream to a stringstream
        std::stringstream log_output;
        auto original_cout_buf = std::cout.rdbuf(log_output.rdbuf());

        // Call printLog()
        game.printLog();

        // Restore the original standard output stream
        std::cout.rdbuf(original_cout_buf);

        // Count the number of lines in the log_output and store unique lines in a set
        int line_count = 0;
        std::string line;
        std::set<std::string> unique_lines;
        while (std::getline(log_output, line)) {
            line_count++;
            unique_lines.insert(line);
        }

        CHECK((line_count == turns));
        CHECK((unique_lines.size() == turns)); // Check if all lines are unique
    }
    SUBCASE("printStats format") {
        Game game = create_new_game();

        // Redirect standard output stream to a stringstream
        std::stringstream stats_output;
        auto original_cout_buf = std::cout.rdbuf(stats_output.rdbuf());

        // Call printStats()
        game.printStats();

        // Restore the original standard output stream
        std::cout.rdbuf(original_cout_buf);

        // Check if the output contains expected keywords or phrases (adjust as needed)
        CHECK((stats_output.str().find("Win rate") != std::string::npos));
        CHECK((stats_output.str().find("Cards won") != std::string::npos));
        CHECK((stats_output.str().find("Draw rate") != std::string::npos));
        CHECK((stats_output.str().find("Amount of draws") != std::string::npos));
    }

    SUBCASE("Test printStats print unique stats for different games") {
        Game game1 = create_new_game();
        Game game2 = create_new_game();

        // Play some turns in each game
        for (int i = 0; i < 5; i++) {
            game1.playTurn();
            game2.playTurn();
        }

        // Play some additional turns in the second game
        for (int i = 0; i < 5; i++) {
            game2.playTurn();
        }

        // Redirect standard output stream to a stringstream for the first game
        std::stringstream stats_output1;
        auto original_cout_buf = std::cout.rdbuf(stats_output1.rdbuf());

        // Call printStats() for the first game
        game1.printStats();

        // Restore the original standard output stream
        std::cout.rdbuf(original_cout_buf);

        // Redirect standard output stream to a stringstream for the second game
        std::stringstream stats_output2;
        original_cout_buf = std::cout.rdbuf(stats_output2.rdbuf());

        // Call printStats() for the second game
        game2.printStats();

        // Restore the original standard output stream
        std::cout.rdbuf(original_cout_buf);

        // Check if the output for the two games is different
        CHECK(stats_output1.str() != stats_output2.str());
    }

    SUBCASE("Test printWiner function") {
        Game g = create_new_game();

        g.playAll();

        std::stringstream ss;
        std::streambuf* old_buf = std::cout.rdbuf(ss.rdbuf()); // Redirect stdout to the stringstream

        g.printWiner();

        std::cout.rdbuf(old_buf); // Restore the original stdout buffer

        if (p1.cardesTaken() > p2.cardesTaken()) {
            // Player 1 is the winner
            CHECK((ss.str().find("Alice") != std::string::npos));
        } else if (p2.cardesTaken() > p1.cardesTaken()) {
            // Player 2 is the winner
            CHECK((ss.str().find("Bob") != std::string::npos));
        } else {
            // It's a draw
            CHECK((ss.str().find("Draw") != std::string::npos));
        }

};}