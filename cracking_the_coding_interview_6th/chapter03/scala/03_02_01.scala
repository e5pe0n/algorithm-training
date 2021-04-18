// Cracking the Coding Interview p.233
package scala

object Constans {
  val INF: Int = 1e9.toInt
}

class Stack(protected val capacity: Int) {
  protected val v: Array[Int] = new Array(capacity)
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

class MinStack(capacity: Int) extends Stack(capacity) {

  private val mins = new Stack(capacity)

  override def push(x: Int): Unit = {
    if (x <= min) mins.push(x)
    super.push(x)
  }

  override def pop(): Int = {
    val x = super.pop()
    if (x == min) mins.pop()

    x
  }

  def min: Int = if (mins.isEmpty) Constans.INF else mins.peek
}

object Main_03_02_01 extends App {
  val ms = new MinStack(10)
  ms.push(5)
  ms.push(3)
  ms.push(7)
  println(ms)
  println(ms.min)
  println()

  ms.pop()
  ms.pop()
  println(ms)
  println(ms.min)
  println()

  ms.push(7)
  ms.push(3)
  ms.push(9)
  ms.push(1)
  println(ms)
  println(ms.min)
  println()

  for (i <- 0 until 4) {
    ms.pop()
    println(ms)
    println(ms.min)
    println()
  }
  println(ms)
  println(ms.min)
}

//   [ 5  3  7  0  0  0  0  0  0  0]
// pt
// 3

//   [ 5  3  7  0  0  0  0  0  0  0]
// pt
// 5

//   [ 5  7  3  9  1  0  0  0  0  0]
// pt
// 1

//   [ 5  7  3  9  1  0  0  0  0  0]
// pt
// 3

//   [ 5  7  3  9  1  0  0  0  0  0]
// pt
// 3

//   [ 5  7  3  9  1  0  0  0  0  0]
// pt
// 5

//   [ 5  7  3  9  1  0  0  0  0  0]
// pt
// 5

//   [ 5  7  3  9  1  0  0  0  0  0]
// pt
// 5
