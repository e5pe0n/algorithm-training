package scala

import scala.collection.mutable.Queue

// final case class EmptyQueueException(
//     private val message: String = "queue is empty",
//     private val cause: Throwable = None.orNull
// ) extends Exception(message, cause)

sealed abstract class Animal {
  val idx: Int
  override def toString(): String = s"Animal: $idx"
}

case class Dog(idx: Int) extends Animal {
  override def toString(): String = s"Dog: $idx"
}

case class Cat(idx: Int) extends Animal {
  override def toString(): String = s"Cat: $idx"
}

class AnimalShelter {
  class Data[T](val ord: Int, val obj: T)

  private var cnt = 0
  private val dog_q: Queue[Data[Dog]] = new Queue
  private val cat_q: Queue[Data[Cat]] = new Queue

  def size: Int = dog_q.size + cat_q.size

  def isEmpty: Boolean = size == 0

  def enqueue(x: Animal): Unit = {
    x match {
      case d @ Dog(idx) => dog_q.enqueue(new Data[Dog](cnt, d))
      case c @ Cat(idx) => cat_q.enqueue(new Data[Cat](cnt, c))
    }
    cnt += 1
  }

  def dequeueAny(): Animal = {
    if (isEmpty) throw new EmptyQueueException
    if (cat_q.size == 0) return dog_q.dequeue().obj
    if (dog_q.size == 0) return cat_q.dequeue().obj
    if (cat_q.front.ord > dog_q.front.ord) return dog_q.dequeue().obj
    else return cat_q.dequeue().obj
  }

  def dequeueDog(): Dog = {
    if (dog_q.size == 0) throw new EmptyQueueException()
    return dog_q.dequeue().obj
  }

  def dequeueCat(): Cat = {
    if (cat_q.size == 0) throw new EmptyQueueException()
    return cat_q.dequeue().obj
  }
}

object Main_03_06_01 extends App {
  val v = Array[Animal](
    new Dog(1),
    new Cat(2),
    new Dog(3),
    new Dog(4),
    new Dog(5),
    new Cat(6),
    new Cat(7),
    new Cat(8),
    new Dog(9),
    new Cat(10),
    new Dog(11),
    new Cat(12),
    new Dog(13)
  )
  val as = new AnimalShelter()
  for (x <- v) as.enqueue(x)

  println(as.dequeueAny())
  println(as.dequeueAny())
  println(as.dequeueAny())
  println()

  println(as.dequeueCat())
  println(as.dequeueCat())
  println(as.dequeueCat())
  println()

  println(as.dequeueDog())
  println(as.dequeueDog())
  println()

  println(as.dequeueCat())
  println(as.dequeueDog())
  println(as.dequeueCat())
  println()

  while (!as.isEmpty) println(as.dequeueAny())
}

// Dog: 1
// Cat: 2
// Dog: 3

// Cat: 6
// Cat: 7
// Cat: 8

// Dog: 4
// Dog: 5

// Cat: 10
// Dog: 9
// Cat: 12

// Dog: 11
// Dog: 13
