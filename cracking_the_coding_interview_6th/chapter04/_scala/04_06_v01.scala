package _scala

import scala.io.Source

object Main_04_06_v01 extends App {
  val MAX = Long.MaxValue
  val MIN = Long.MinValue

  case class Node(
      val idx: Int,
      val x: Long,
      var par: Node = null,
      var left: Node = null,
      var right: Node = null
  ) {
    override def toString(): String = s"($left $x $right)"
  }

  class Tree(val root: Node) {
    override def toString(): String = root.toString()
  }

  def makeTree(v: Array[Long], edges: Array[(Long, Long, String)]): Tree = {
    val nodes = v.zipWithIndex.map { case (x, i) => new Node(i, x) }
    for ((u, v, c) <- edges) {
      c match {
        case "l" => {
          nodes(u.toInt).left = nodes(v.toInt)
          nodes(v.toInt).par = nodes(u.toInt)
        }
        case _ => {
          nodes(u.toInt).right = nodes(v.toInt)
          nodes(v.toInt).par = nodes(u.toInt)
        }
      }
    }

    new Tree(nodes(0))
  }

  def _getNode(node: Node, nodeIdx: Int): Node =
    if (node == null) null
    else if (node.idx == nodeIdx) node
    else {
      val node_l = _getNode(node.left, nodeIdx)
      val node_r = _getNode(node.right, nodeIdx)
      if (node_l != null) node_l
      else if (node_r != null) node_r
      else null
    }

  def getNode(tree: Tree, nodeIdx: Int): Node = _getNode(tree.root, nodeIdx)

  def getSucc(tree: Tree, nodeIdx: Int): Node = {
    var node = getNode(tree, nodeIdx)
    if (node == null) null
    else if (node.right != null) {
      def mostLeft(n: Node): Node = n match {
        case Node(_, _, _, null, _) => n
        case _                      => mostLeft(n.left)
      }

      mostLeft(node.right)
    } else {
      def rightPar(par: Node, child: Node): Node = par match {
        case null                      => null
        case Node(_, _, _, `child`, _) => par
        case _                         => rightPar(par.par, par)
      }

      rightPar(node.par, node)
    }
  }

  def solve(fp: String): Unit = {
    println(f"# $fp")
    val lines = Source.fromFile(fp).getLines()
    val Array(n, k) = lines.next().split(' ').map(x => x.toLong)
    val v = lines.next().split(' ').map(x => x.toLong)
    val edges = (for (_ <- 0L until n - 1) yield {
      val Array(u, v, c) = lines.next().split(' ')

      (u.toLong - 1, v.toLong - 1, c)
    }).toArray
    val tree = makeTree(v, edges)
    val res = getSucc(tree, (k - 1).toInt)
    println(if (res != null) res.idx + 1 else null)
    println
  }

  solve("../testcases/04_06/01.txt")
  solve("../testcases/04_06/02.txt")
  solve("../testcases/04_06/03.txt")
  solve("../testcases/04_06/04.txt")
  solve("../testcases/04_06/05.txt")
}

// # ../testcases/04_06/01.txt
// 11

// # ../testcases/04_06/02.txt
// 12

// # ../testcases/04_06/03.txt
// 1

// # ../testcases/04_06/04.txt
// 6

// # ../testcases/04_06/05.txt
// null
