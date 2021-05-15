from typing import Callable, List, Iterable, Union
from abc import ABC
from enum import Enum, auto
from random import shuffle


class Suits(Enum):
    diamond = auto()
    club = auto()
    spade = auto()
    heart = auto()

    def __str__(self) -> str:
        return self.name


class Card(ABC):
    def repr(self, *args: Iterable[str]) -> str:
        return f"Card({', '.join(args)})"


class OrdinalCard(Card):
    def __init__(self, suit: Suits, rank: int):
        if rank < 0 or 13 < rank:
            raise ValueError("rank must be in [1, 13]")
        self.__suit = suit
        self.__rank = rank

    def __repr__(self) -> str:
        return self.repr(str(self.__suit), str(self.__rank))

    def suit(self) -> Suits:
        return self.__suit

    def rank(self) -> int:
        return self.__rank


class Joker(Card):
    def __repr__(self) -> str:
        return self.repr("Joker")


Cards = List[Card]
DeckInitializer = Callable[[], Cards]


def default_deck_initializer_without_jokers() -> Cards:
    return [OrdinalCard(s, i) for (s, _) in Suits.__members__.items() for i in range(1, 14)]


def default_deck_initializer() -> Cards:
    return default_deck_initializer_without_jokers + [Joker(), Joker()]


class Deck:
    def __init__(self, initializer: Union[Cards, DeckInitializer]):
        if isinstance(initializer, list):
            self.__cards = initializer
        elif callable(initializer):
            self.__cards = initializer()
        else:
            raise ValueError(
                "Invalid argument; initializer must be a Cards or DeckInitializer object")

    def __len__(self) -> int:
        return len(self.__cards)

    def shuffle(self) -> None:
        shuffle(self.__cards)

    def put(self, card: Card) -> None:
        self.__cards.append(card)

    def draw(self) -> Card:
        if len(self) == 0:
            raise ValueError("deck is empty")
        return self.__cards.pop()


def main():
    BJ_deck = Deck(default_deck_initializer_without_jokers)
    BJ_deck.shuffle()
    c1 = BJ_deck.draw()
    print(c1)
    c2 = BJ_deck.draw()
    print(c2)
    c3 = BJ_deck.draw()
    print(c3)

# Card(spade, 7)
# Card(diamond, 10)
# Card(spade, 2)


if __name__ == "__main__":
    main()
