package _scala

import scala.io.Source

object Main_04_05_v02 extends App {
  val MAX = Long.MaxValue
  val MIN = Long.MinValue

  case class Node(val x: Long, var left: Node = null, var right: Node = null) {
    override def toString(): String = s"($left $x $right)"
  }

  class Tree(val root: Node) {
    override def toString(): String = root.toString()
  }

  def makeTree(v: Array[Long], edges: Array[(Long, Long, String)]): Tree = {
    val nodes = v.map(x => new Node(x))
    for ((u, v, c) <- edges) {
      c match {
        case "l" => nodes(u.toInt).left = nodes(v.toInt)
        case _   => nodes(u.toInt).right = nodes(v.toInt)
      }
    }

    new Tree(nodes(0))
  }

  def isWithinRange(node: Node, lb: Long, ub: Long): Boolean =
    if (node == null) true
    else
      isWithinRange(node.left, lb, node.x) && isWithinRange(
        node.right,
        node.x + 1,
        ub
      ) && lb <= node.x && node.x <= ub

  def isValidBST(tree: Tree): Boolean =
    if (tree.root == null) false else isWithinRange(tree.root, MIN, MAX)

  def solve(fp: String): Unit = {
    println(f"# $fp")
    val lines = Source.fromFile(fp).getLines()
    val n = lines.next().toLong
    val v = lines.next().split(' ').map(x => x.toLong)
    val edges = (for (_ <- 0L until n - 1) yield {
      val Array(u, v, c) = lines.next().split(' ')

      (u.toLong - 1, v.toLong - 1, c)
    }).toArray
    val tree = makeTree(v, edges)
    println(isValidBST(tree))
    println
  }

  solve("../testcases/04_05/01.txt")
  solve("../testcases/04_05/02.txt")
  solve("../testcases/04_05/03.txt")
  solve("../testcases/04_05/04.txt")
  solve("../testcases/04_05/05.txt")
  solve("../testcases/04_05/06.txt")
  solve("../testcases/04_05/07.txt")
  solve("../testcases/04_05/08.txt")
  solve("../testcases/04_05/09.txt")
}

// # ../testcases/04_05/01.txt
// true

// # ../testcases/04_05/02.txt
// false

// # ../testcases/04_05/03.txt
// true

// # ../testcases/04_05/04.txt
// false

// # ../testcases/04_05/05.txt
// true

// # ../testcases/04_05/06.txt
// false

// # ../testcases/04_05/07.txt
// true

// # ../testcases/04_05/08.txt
// false

// # ../testcases/04_05/09.txt
// false
