package _scala

import scala.io.Source
import scala.collection.mutable.{ListBuffer}
import scala.collection.mutable.ArrayBuffer

object Main_04_09_v02 extends App {
  case class Node(val x: Int, var left: Node = null, var right: Node = null) {
    override def toString(): String = s"($left $x $right)"
  }

  class Tree(val root: Node) {
    override def toString(): String = root.toString()
  }

  def connNodes(nodes: Array[Node], left: Int, right: Int): Node =
    right - left match {
      case 0 => null
      case 1 => nodes(left)
      case _ => {
        val mid = (left + right) / 2
        nodes(mid).left = connNodes(nodes, left, mid)
        nodes(mid).right = connNodes(nodes, mid + 1, right)
        nodes(mid)
      }
    }

  def makeBst(n: Int): Tree = {
    val nodes = (for (i <- 0 until n) yield new Node(i)).toArray
    new Tree(connNodes(nodes, 0, n))
  }

  def weaveList(
      fst: ListBuffer[Int],
      snd: ListBuffer[Int],
      ress: ArrayBuffer[ListBuffer[Int]],
      pre: ListBuffer[Int]
  ): Unit =
    if (fst.size == 0 || snd.size == 0) ress += pre ++ fst ++ snd
    else {
      val head_fst = fst.remove(0)
      pre += head_fst
      weaveList(fst, snd, ress, pre)
      pre.remove(pre.size - 1)
      head_fst +=: fst

      val head_snd = snd.remove(0)
      pre += head_snd
      weaveList(fst, snd, ress, pre)
      pre.remove(pre.size - 1)
      head_snd +=: snd
    }

  def _allSequences(node: Node): ArrayBuffer[ListBuffer[Int]] = {
    val res = new ArrayBuffer[ListBuffer[Int]]
    node match {
      case null => {
        res += new ListBuffer[Int]
        res
      }
      case _ => {
        val pre = new ListBuffer[Int]
        pre += node.x

        val left_seq = _allSequences(node.left)
        val right_seq = _allSequences(node.right)

        for (left <- left_seq) {
          for (right <- right_seq) {
            val weaved = new ArrayBuffer[ListBuffer[Int]]
            weaveList(left, right, weaved, pre)
            res ++= weaved
          }
        }
        res
      }
    }
  }

  def allSequences(tree: Tree): ArrayBuffer[ListBuffer[Int]] = _allSequences(tree.root)

  def solve(fp: String): Unit = {
    println(s"# $fp")
    val lines = Source.fromFile(fp).getLines()
    val n = lines.next().toInt
    val tree = makeBst(n)
    println(tree)
    val res = allSequences(tree)
    for (lst <- res) {
      println(lst.map(x => (x + 1).toString).mkString(" "))
    }
    println
  }

  solve("../testcases/04_09/01.txt")
  solve("../testcases/04_09/02.txt")
  solve("../testcases/04_09/03.txt")
}
