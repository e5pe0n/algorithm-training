package scala

final case class EmptyQueueException(
    private val message: String = "queue is empty",
    private val cause: Throwable = None.orNull
) extends Exception(message, cause)

final case class FullQueueException(
    private val message: String = "queue is full",
    private val cause: Throwable = None.orNull
) extends Exception(message, cause)

class Stack3(protected val capacity: Int) {
  val v: Array[Int] = new Array(capacity)
  protected var pt: Int = 0

  def size: Int = pt

  def push(x: Int): Unit = {
    if (isFull) throw new FullStackException
    v(pt) = x
    pt += 1
  }

  def pop(): Int = {
    if (isEmpty) throw new EmptyStackException
    pt -= 1

    v(pt)
  }

  def peek(): Int = {
    if (isEmpty) throw new EmptyStackException

    v(pt - 1)
  }

  def isEmpty(): Boolean = size == 0
  def isFull(): Boolean = size == capacity
  override def toString(): String = {
    var res = new StringBuilder
    res ++= (for (x <- v) yield f"$x%2d").mkString("  [", " ", "]\n")
    res ++= (for (i <- 0 until size) yield if (i == pt) " ^" else "  ").mkString("pt ", " ", "")

    res.toString
  }
}

class MyQueue(private val capacity: Int) {
  private val input = new Stack3(capacity)
  private val output = new Stack3(capacity)

  def size: Int = input.size + output.size

  override def toString(): String =
    (for (x <- (input.v ++ output.v)) yield f"$x%2d").mkString("[", " ", "]")

  def enqueue(x: Int): Unit =
    if (isFull) throw new FullQueueException else input.push(x)

  def dequeue(): Int =
    if (isEmpty) throw new EmptyQueueException
    else {
      if (output.isEmpty) migrate()

      output.pop()
    }

  def peek(): Int = if (isEmpty) throw new EmptyQueueException
  else {
    if (output.isEmpty) migrate()

    output.peek
  }

  def migrate(): Unit = while (!input.isEmpty) output.push(input.pop())
  def isEmpty(): Boolean = size == 0
  def isFull(): Boolean = size == capacity
}

object Main_03_04_01 extends App {
  val mq = new MyQueue(10)
  for (i <- 10 until 20) mq.enqueue(i)
  println(mq)
  for (i <- 0 until 10) println(mq.dequeue())
  println(mq)
  for (i <- 50 until 54) mq.enqueue(i)
  println(mq)
  for (i <- 0 until 2) println(mq.dequeue())
  println(mq)
}

// [10 11 12 13 14 15 16 17 18 19  0  0  0  0  0  0  0  0  0  0]
// 10
// 11
// 12
// 13
// 14
// 15
// 16
// 17
// 18
// 19
// [10 11 12 13 14 15 16 17 18 19 19 18 17 16 15 14 13 12 11 10]
// [50 51 52 53 14 15 16 17 18 19 19 18 17 16 15 14 13 12 11 10]
// 50
// 51
// [50 51 52 53 14 15 16 17 18 19 53 52 51 50 15 14 13 12 11 10]
