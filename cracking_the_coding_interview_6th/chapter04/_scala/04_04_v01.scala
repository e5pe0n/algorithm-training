package _scala

import scala.io.Source
import scala.math.{max, abs}

object Main_04_04_v01 extends App {
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

  def dfs(node: Node): (Int, Boolean) = node match {
    case Node(_, null, null) => (0, true)
    case Node(_, _, null) => {
      val (height, balanced) = dfs(node.left)

      (height + 1, balanced)
    }
    case Node(_, null, _) => {
      val (height, balanced) = dfs(node.right)

      (height + 1, balanced)
    }
    case _ => {
      val (height_l, balanced_l) = dfs(node.left)
      val (height_r, balanced_r) = dfs(node.right)

      (max(height_l, height_r) + 1, abs(height_l - height_r) <= 1 && balanced_l && balanced_r)
    }
  }

  def isBalanced(tree: Tree): Boolean =
    if (tree.root == null) false
    else {
      val (_, balanced) = dfs(tree.root)

      balanced
    }

  def solve(fp: String): Unit = {
    println(f"# $fp")
    val lines = Source.fromFile(fp).getLines()
    val n = lines.next().toInt
    val edges = (for (i <- 0 until n - 1) yield {
      val Array(u, v, c) = lines.next().split(' ')
      (u.toInt - 1, v.toInt - 1, c)
    }).toArray
    val tree = makeTree(n, edges)
    println(if (isBalanced(tree)) "balanced" else "unbalanced")
    println
  }

  solve("../testcases/04_04/01.txt")
  solve("../testcases/04_04/02.txt")
  solve("../testcases/04_04/03.txt")
  solve("../testcases/04_04/04.txt")
}

// # ../testcases/04_04/01.txt
// balanced

// # ../testcases/04_04/02.txt
// balanced

// # ../testcases/04_04/03.txt
// unbalanced

// # ../testcases/04_04/04.txt
// unbalanced
