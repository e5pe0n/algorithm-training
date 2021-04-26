package _scala

import scala.io.Source

object Main_04_10_v02 extends App {
  case class Node(val x: Int, var left: Node = null, var right: Node = null) {
    override def toString(): String = s"($left $x $right)"
  }

  class Tree(val root: Node) {
    override def toString(): String = root.toString()
  }

  def makeBT(root: Int, nodeIdxs: Array[Int], edges: Array[(Int, Int, String)]): Tree = {
    val nodes = (for (idx <- nodeIdxs) yield (idx, new Node(idx))).toMap
    for ((u, v, c) <- edges) {
      c match {
        case "l" => nodes(u).left = nodes(v)
        case _   => nodes(u).right = nodes(v)
      }
    }
    new Tree(nodes(root))
  }

  def getOrderString(node: Node, sb: StringBuilder): Unit =
    if (node == null) sb += 'X'
    else {
      sb ++= s"${node.x} "
      getOrderString(node.left, sb)
      getOrderString(node.right, sb)
    }

  def containsTree(t1: Tree, t2: Tree): Boolean = {
    val sb1 = new StringBuilder
    val sb2 = new StringBuilder
    getOrderString(t1.root, sb1)
    getOrderString(t2.root, sb2)
    val s1 = sb1.toString()
    val s2 = sb2.toString()
    s1 contains s2
  }

  def readArgs(fp: String): Array[(Int, Array[Int], Array[(Int, Int, String)])] = {
    val lines = Source.fromFile(fp).getLines()
    val Array(n, a) = lines.next().split(' ').map(x => x.toInt)
    val nodeIdxs1 = lines.next().split(' ').map(x => x.toInt)
    val edges1 = (for (i <- 0 until (n - 1)) yield {
      val Array(u, v, c) = lines.next().split(' ')
      (u.toInt, v.toInt, c)
    }).toArray
    val Array(m, b) = lines.next().split(' ').map(x => x.toInt)
    val nodeIdxs2 = lines.next().split(' ').map(x => x.toInt)
    val edges2 = (for (i <- 0 until (m - 1)) yield {
      val Array(p, q, c) = lines.next().split(' ')
      (p.toInt, q.toInt, c)
    }).toArray
    Array((a, nodeIdxs1, edges1), (b, nodeIdxs2, edges2))
  }

  def solve(fp: String): Unit = {
    println(s"# $fp")
    val Array(args1, args2) = readArgs(fp)
    val t1 = Function.tupled(makeBT _)(args1)
    val t2 = Function.tupled(makeBT _)(args2)
    println(containsTree(t1, t2))
    println
  }

  solve("../testcases/04_10/01.txt")
  solve("../testcases/04_10/02.txt")
  solve("../testcases/04_10/03.txt")
  solve("../testcases/04_10/04.txt")
  solve("../testcases/04_10/05.txt")
  solve("../testcases/04_10/06.txt")
  solve("../testcases/04_10/07.txt")
  solve("../testcases/04_10/08.txt")
  solve("../testcases/04_10/09.txt")
}

// # ../testcases/04_10/01.txt
// true

// # ../testcases/04_10/02.txt
// true

// # ../testcases/04_10/03.txt
// true

// # ../testcases/04_10/04.txt
// true

// # ../testcases/04_10/05.txt
// true

// # ../testcases/04_10/06.txt
// false

// # ../testcases/04_10/07.txt
// false

// # ../testcases/04_10/08.txt
// false

// # ../testcases/04_10/09.txt
// false
