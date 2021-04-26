package _scala

import scala.io.Source

object Main_04_10_v01 extends App {
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

  def isSameTree(node1: Node, node2: Node): Boolean =
    if (node1 == null && node2 == null) true
    else if (node1 == null || node2 == null) false
    else if (node1.x != node2.x) false
    else isSameTree(node1.left, node2.left) && isSameTree(node1.right, node2.right)

  def _isSubTree(node: Node, subRoot: Node): Boolean =
    if (node == null) false
    else if (node.x == subRoot.x && isSameTree(node, subRoot)) true
    else if (_isSubTree(node.left, subRoot)) true
    else _isSubTree(node.right, subRoot)

  def isSubTree(tree: Tree, sub: Tree) = _isSubTree(tree.root, sub.root)

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
    println(isSubTree(t1, t2))
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
