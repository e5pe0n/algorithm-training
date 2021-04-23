package _scala

import scala.io.Source
import scala.collection.mutable.{ArrayBuffer, ArrayDeque}

object Main_04_07_v02 extends App {
  def dfs(
      u: Int,
      graph: Array[ArrayBuffer[Int]],
      q: ArrayDeque[Int],
      added: Array[Boolean],
      used: Array[Boolean]
  ): Boolean = {
    var res = true
    for (v <- graph(u)) {
      if (used(v)) return false
      if (!added(v)) {
        used(v) = true
        res &= dfs(v, graph, q, added, used)
        used(v) = false
      }
    }
    u +=: q
    added(u) = true
    res
  }

  def getBuildOrder(n: Int, graph: Array[ArrayBuffer[Int]]): Array[Int] = {
    val q = new ArrayDeque[Int]
    var added = new Array[Boolean](n)
    for (u <- 0 until n) {
      if (!added(u)) {
        val used = new Array[Boolean](n)
        used(u) = true
        if (!dfs(u, graph, q, added, used)) return new Array[Int](0)
      }
    }
    added = new Array[Boolean](n)
    val res = new Array[Int](n)
    var idx = n - 1
    while (q.nonEmpty) {
      val u = q.removeLast()
      if (!added(u)) {
        res(idx) = u
        idx -= 1
        added(u) = true
      }
    }
    res
  }

  def solve(fp: String): Unit = {
    println(f"# $fp")
    val lines = Source.fromFile(fp).getLines()
    val Array(n, m) = lines.next().split(' ').map(x => x.toInt)
    val graph = new Array[ArrayBuffer[Int]](n).map(_ => new ArrayBuffer[Int])
    for (i <- 0 until m) {
      val Array(u, v) = lines.next().split(' ').map(x => x.toInt - 1)
      graph(u) += v
    }
    val res = getBuildOrder(n, graph)
    println(if (res.size > 0) res.map(x => (x + 1).toString).mkString(" ") else "error")
    println()
  }

  solve("../testcases/04_07/01.txt")
  solve("../testcases/04_07/02.txt")
  solve("../testcases/04_07/03.txt")
  solve("../testcases/04_07/04.txt")
  solve("../testcases/04_07/05.txt")
  solve("../testcases/04_07/06.txt")
}

// # ../testcases/04_07/01.txt
// 6 5 2 1 4 3

// # ../testcases/04_07/02.txt
// error

// # ../testcases/04_07/03.txt
// 8 3 2 1 5 12 9 4 7 6 10 11

// # ../testcases/04_07/04.txt
// error

// # ../testcases/04_07/05.txt
// 2 1

// # ../testcases/04_07/06.txt
// error
