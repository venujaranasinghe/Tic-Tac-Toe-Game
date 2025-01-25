<h1 align="center">Tic-Tac-Toe Game 🎮</h1>

<p align="center">A simple console-based Tic-Tac-Toe game implemented in C. This project was created as part of a university assignment to demonstrate modular programming by separating functions into `.c` and `.h` files.</p>

---

<h2>Description 📝</h2>
<p>This project implements a two-player Tic-Tac-Toe game where players take turns to mark spaces in a 3x3 grid. The game checks for valid moves, detects winners, and declares a draw if all spaces are filled without a winner.</p>

---

<h2>Features ✨</h2>
<ul>
  <li><b>Two-Player Mode:</b> Play against a friend in turn-based gameplay.</li>
  <li><b>Console-Based:</b> Lightweight game running directly in the terminal.</li>
  <li><b>Modular Design:</b> Functions are organized in separate `.h` and `.c` files for better code structure.</li>
  <li><b>Error Handling:</b> Ensures players input valid moves.</li>
</ul>

---

<h2>Technologies Used 💻</h2>
<ul>
  <li><b>Language:</b> C</li>
  <li><b>Compiler:</b> GCC (or any standard C compiler)</li>
</ul>

---

<h2>Setup Instructions ⚙️</h2>
<ol>
  <li>Clone the repository:
    <pre><code>git clone https://github.com/venujaranasinghe/Tic-Tac-Toe-Game.git  
cd Tic-Tac-Toe-Game</code></pre>
  </li>
  <li>Compile the program:
    <pre><code>gcc main.c -o tictactoe</code></pre>
  </li>
  <li>Run the game:
    <pre><code>./tictactoe</code></pre>
  </li>
</ol>

---

<h2>Folder Structure 📂</h2>
<ul>
  <li><code>main.c</code> – Contains the main game loop and handles game flow.</li>
  <li><code>functions.h</code> – Includes all helper functions for game logic, such as move validation, board display, and win checks.</li>
</ul>

---

<h2>How to Play 🎲</h2>
<ol>
  <li>Player 1 uses 'X' and Player 2 uses 'O'.</li>
  <li>Players take turns entering the position number (1-9) corresponding to the grid cell:</li>
</ol>
<pre>
  1 | 2 | 3
  ---------
  4 | 5 | 6
  ---------
  7 | 8 | 9
</pre>
<ol start="3">
  <li>The game declares a winner if a player aligns three of their marks horizontally, vertically, or diagonally.</li>
  <li>If all spaces are filled without a winner, the game declares a draw.</li>
</ol>

---

<h2>Contribution 🤝</h2>
<p>Feel free to fork the repository, make improvements, and submit a pull request.</p>

---

<h2>License 📝</h2>
<p>Pending...</p>

---

<h2>Contact</h2>
<p>Developed by <b>Venuja Ranasinghe</b>.</p>
<p>GitHub: <a href="https://github.com/venujaranasinghe">venujaranasinghe</a></p>
