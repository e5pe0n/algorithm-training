package scala

final case class EmptyStackException(
    private val message: String = "stack is empty",
    private val cause: Throwable = None.orNull
) extends Exception(message, cause)

final case class FullStackException(
    private val message: String = "stack is full",
    private val cause: Throwable = None.orNull
) extends Exception(message, cause)

class ThreeInOne(val eachSize: Int) {
  class Stack(var btm: Int, var size: Int) {
    var pt = btm
  }

  private val v: Array[Int] = new Array(eachSize * 3)
  val s1 = new Stack(0, eachSize)
  val s2 = new Stack(eachSize, eachSize)
  val s3 = new Stack(eachSize * 2, eachSize)

  override def toString(): String = {
    var res = new StringBuilder
    res ++= (for (x <- v) yield f"$x%2d").mkString("   [", " ", "]\n")
    res ++= (for (i <- (0 until v.length))
      yield if (i == s1.btm || i == s2.btm || i == s3.btm) " ^" else "  ")
      .mkString("btm ", " ", "\n")
    res ++= (for (i <- (0 until v.length))
      yield if (i == s1.pt || i == s2.pt || i == s3.pt) " ^" else "  ").mkString("pt  ", " ", "\n")
    res.toString
  }

  def pop(s: Stack): Int =
    if (isEmpty(s)) throw new EmptyStackException
    else {
      s.pt -= 1
      v(s.pt)
    }

  def push(s: Stack, x: Int): Unit =
    if (isFull(s)) throw new FullStackException
    else {
      v(s.pt) = x
      s.pt += 1
    }

  def peek(s: Stack): Int =
    if (isEmpty(s)) throw new EmptyStackException
    else v(s.pt - 1)

  def isEmpty(s: Stack): Boolean = s.pt <= s.btm
  def isFull(s: Stack): Boolean = s.pt - s.btm >= s.size
}

object Main_03_01_01 extends App {
  private val tio = new ThreeInOne(5)
  for (i <- (10 until 13)) {
    tio.push(tio.s1, i)
    tio.push(tio.s2, i)
    tio.push(tio.s3, i)
  }
  println(tio)
  println(tio.pop(tio.s1))
  println(tio.pop(tio.s1))
  println(tio)
  println(tio.pop(tio.s2))
  println(tio.pop(tio.s3))
  println(tio.pop(tio.s3))
  println(tio)
  println(tio.peek(tio.s1))
  println(tio.peek(tio.s2))
  println(tio.peek(tio.s3))

  tio.push(tio.s1, 20)
  tio.push(tio.s2, 20)
  tio.push(tio.s3, 20)
  println(tio)
}

//    [10 11 12  0  0 10 11 12  0  0 10 11 12  0  0]
// btm  ^              ^              ^
// pt            ^              ^              ^

// 12
// 11
//    [10 11 12  0  0 10 11 12  0  0 10 11 12  0  0]
// btm  ^              ^              ^
// pt      ^                    ^              ^

// 12
// 12
// 11
//    [10 11 12  0  0 10 11 12  0  0 10 11 12  0  0]
// btm  ^              ^              ^
// pt      ^                 ^           ^

// 10
// 11
// 10
//    [10 20 12  0  0 10 11 20  0  0 10 20 12  0  0]
// btm  ^              ^              ^
// pt         ^                 ^           ^
