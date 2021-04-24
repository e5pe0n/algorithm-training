package _scala

import scala.io.Source

object Main_04_08_v01 extends App {
  case class Node(val x: Int, var left: Node = null, var right: Node = null) {
    override def toString(): String = s"($left $x $right)"
  }

  class Tree(val root: Node) {
    override def toString(): String = root.toString()
  }

  def makeTree(n: Int, edges: Array[(Int, Int, String)]): Tree = {
    val nodes = (for (i <- 0 until n) yield new Node(i)).toArray
    for ((u, v, c) <- edges) {
      c match {
        case "l" => nodes(u).left = nodes(v)
        case _   => nodes(u).right = nodes(v)
      }
    }

    new Tree(nodes(0))
  }

  def _getNode(node: Node, nodeIdx: Int): Node = {
    if (node == null) return null
    if (node.x == nodeIdx) return node
    val res_l = _getNode(node.left, nodeIdx)
    if (res_l != null) return res_l
    val res_r = _getNode(node.right, nodeIdx)
    if (res_r != null) return res_r
    null
  }

  def getNode(tree: Tree, nodeIdx: Int): Node = _getNode(tree.root, nodeIdx)

  def dfs(node: Node, s: Node, t: Node): (Node, Boolean) = {
    if (node == null) return (null, false)
    if (node == s || node == t) return (null, true)
    val res_l = dfs(node.left, s, t)
    if (res_l._1 != null) return res_l
    val res_r = dfs(node.right, s, t)
    if (res_r._1 != null) return res_r
    if (res_l._2 && res_r._2) return (node, true)
    (null, res_l._2 || res_r._2)
  }

  def searchFirstCommonAncestor(tree: Tree, s: Node, t: Node): Node = dfs(tree.root, s, t) match {
    case (ans, _) => ans
  }

  def solve(fp: String): Unit = {
    println(f"# $fp")
    val lines = Source.fromFile(fp).getLines()
    val (n, s, t) = lines.next().split(' ').map(x => x.toInt) match {
      case Array(n, s, t) => (n, s - 1, t - 1)
    }
    val edges = (for (i <- 0 until n - 1) yield {
      val Array(u, v, c) = lines.next().split(' ')
      (u.toInt - 1, v.toInt - 1, c)
    }).toArray
    val tree = makeTree(n, edges)
    val des1 = getNode(tree, s)
    val des2 = getNode(tree, t)
    val res = searchFirstCommonAncestor(tree, des1, des2)
    println(if (res != null) (res.x + 1).toString else null)
    println
  }

  solve("../testcases/04_08/01.txt")
  solve("../testcases/04_08/02.txt")
  solve("../testcases/04_08/03.txt")
  solve("../testcases/04_08/04.txt")
}

// # ../testcases/04_08/01.txt
// 2

// # ../testcases/04_08/02.txt
// 2

// # ../testcases/04_08/03.txt
// 1

// # ../testcases/04_08/04.txt
// null
