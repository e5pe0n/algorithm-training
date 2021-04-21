package _scala

import scala.io.Source

object Main_04_02_v01 extends App {
  case class Node(val x: Int, val left: Node = null, val right: Node = null) {
    override def toString(): String = s"($left $x $right)"
  }

  class Tree(val root: Node) {
    override def toString(): String = root.toString()
  }

  def rec(v: Array[Int], left: Int, right: Int): Node = (right - left) match {
    case 0 => null
    case 1 => new Node(v(left))
    case _ => {
      val mid = (left + right) / 2
      val lc = rec(v, left, mid)
      val rc = rec(v, mid + 1, right)

      new Node(v(mid), lc, rc)
    }
  }

  def makeMinBST(v: Array[Int]): Tree = new Tree(rec(v, 0, v.size))

  def solve(fp: String): Unit = {
    val lines = Source.fromFile(fp).getLines()
    lines.next()
    val v = lines.next().split(' ').map(x => x.toInt)
    val res = makeMinBST(v)
    println(res)
  }

  solve("../testcases/04_02/01.txt")
  solve("../testcases/04_02/02.txt")
  solve("../testcases/04_02/03.txt")
  solve("../testcases/04_02/04.txt")
}

// (((null 1 null) 2 (null 3 null)) 4 ((null 5 null) 6 (null 7 null)))
// ((((null 1 null) 2 null) 3 (null 4 null)) 5 ((null 6 null) 7 (null 8 null)))
// ((((null 1 null) 2 null) 3 ((null 4 null) 5 null)) 6 (((null 7 null) 8 null) 9 (null 10 null)))
// ((null 1 null) 2 null)
