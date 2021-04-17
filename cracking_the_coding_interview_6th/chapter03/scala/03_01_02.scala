package scala

class ThreeInOne2(val eachSize: Int) {
  class Stack(var btm: Int, var size: Int) {
    var pt = btm
  }

  private val v: Array[Int] = new Array(eachSize * 3)
  val size = v.length
  val s1 = new Stack(0, eachSize)
  val s2 = new Stack(eachSize, eachSize)
  val s3 = new Stack(eachSize * 2, eachSize)

  override def toString(): String = {
    var res = new StringBuilder
    res ++= (for (x <- v) yield f"$x%2d").mkString("   [", " ", "]\n")
    res ++= (for (i <- (0 until v.length))
      yield
        if (i == s1.btm || i == s2.btm || i == s3.btm) " ^" else "  ").mkString("btm ", " ", "\n")
    res ++= (for (i <- (0 until v.length))
      yield if (i == s1.pt || i == s2.pt || i == s3.pt) " ^" else "  ").mkString("pt  ", " ", "\n")
    res.toString
  }

  private def _pt(s: Stack): Int = if (s.pt < s.btm) s.pt + size else s.pt

  def pop(s: Stack): Int =
    if (isEmpty(s)) throw new EmptyStackException
    else {
      s.pt = ((s.pt - 1) % size + size) % size
      v(s.pt)
    }

  def push(s: Stack, x: Int): Unit = {
    if (isFull(s)) modify(s)
    v(s.pt) = x
    s.pt = (s.pt + 1) % size
  }

  def peek(s: Stack): Int =
    if (isEmpty(s)) throw new EmptyStackException
    else v(s.pt - 1)

  def isEmpty(s: Stack): Boolean = s.pt == s.btm
  def isFull(s: Stack): Boolean = _pt(s) - s.btm >= s.size
  def areAllFull: Boolean = (_pt(s1) - s1.btm) + (_pt(s2) - s2.btm) + (_pt(s3) - s3.btm) >= size

  private def shift(s: Stack): Unit = {
    for (i <- _pt(s) until s.btm by -1) {
      v(i % size) = v(((i - 1) % size + size) % size)
    }
    s.btm = (s.btm + 1) % size
    s.pt = (s.pt + 1) % size
  }

  private def shrink(s: Stack): Unit = {
    shift(s)
    s.size -= 1
  }

  private def _modify(target: Stack, next: Stack, next_next: Stack): Unit = {
    if (!isFull(next)) shrink(next)
    else {
      shrink(next_next)
      shift(next)
    }
    target.size += 1
  }

  private def modify(s: Stack): Unit = {
    if (areAllFull) throw new FullStackException
    s match {
      case `s1` => _modify(s1, s2, s3)
      case `s2` => _modify(s2, s3, s1)
      case `s3` => _modify(s3, s1, s2)
      case _    =>
    }
    assert(
      s1.size + s2.size + s3.size == size
        && (_pt(s1) - s1.btm) + (_pt(s2) - s2.btm) + (_pt(s3) - s3.btm) <= size
    )
  }
}
