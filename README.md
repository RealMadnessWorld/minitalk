<h1 align="center">
  <img src="https://user-images.githubusercontent.com/76601093/196039712-ffd15bb3-8fd2-4aac-b8a1-f5a4481836e4.jpg" align="left" width=250> Minitalk <img src="https://user-images.githubusercontent.com/76601093/196040617-064194a4-56f0-4116-aec5-1bd3d6cb5230.png" align="right" width=150>
</h1>

<div align="center">
  <blockquote>
    "The purpose of this project is to code a small data exchange program using UNIX signals"
  </blockquote>
</div>

---

<h2 align="center">
  Objective
</h2>

In this project there will be two executables:
  - The client that sends a string to the server using UNIX signals: SIGUSER1 and SIGUSER2
  - And the server that receives the signals and converts them back to a string

The bonus part of the exercise has as an objective:
  - The server acknowledges every message received by sending back a signal to the client.
  - Supports Unicode characters

---

<h3 align="center">
  How to use:
</h3>

- Run Makefile with:
    
      make
      
- Start server with ```./server``` and copy his pid address (the server will show you the pid when you run it)

     ![image](https://user-images.githubusercontent.com/76601093/196054889-2adb01a2-bc2f-49aa-a7ba-3b9d3f62da48.png)

- Open a new terminal, start the client and give him the server pid and the string you want to send
    
    ![image](https://user-images.githubusercontent.com/76601093/196055240-84f39f6f-36fd-45a1-9f60-38a7c9092ead.png)

After that that the text should appear on the server terminal.

<br>

For the bonus part it works exactly the same but instead of make you run ```make bonus```

