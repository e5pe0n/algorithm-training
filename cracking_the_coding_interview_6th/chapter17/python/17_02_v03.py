from typing import List
from enum import Enum, auto
import random


class Suit(Enum):
    HEART = auto()
    DIAMOND = auto()
    SPADE = auto()
    CLOVER = auto()


class Card:
    def __init__(self, rank: int, suit: Suit):
        self.rank: int = rank
        self.suit: Suit = suit

    def __repr__(self):
        return f"({self.rank}, {self.suit})"


def make_deck():
    return [Card(i, s) for s in Suit for i in range(1, 14)]


def shuffle(cards: List[Card]) -> None:
    if len(cards) == 0:
        return
    for i in range(1, len(cards)):
        x = int(random.uniform(0, i))
        cards[x], cards[i] = cards[i], cards[x]
    return


deck = make_deck()
shuffle(deck)
print(deck[:5])
