# Pong SFML + AtlasSDK

## Overview

**Pong SFML + AtlasSDK** is a modern reimplementation of the classic *Pong* game, developed as a portfolio project and as a practical validation tool for my custom C++ library, **AtlasSDK**.

The project deliberately separates responsibilities:

* **AtlasSDK** is used for *mathematical transforms, spatial representation, and collision detection*.
* **SFML** (Simple and Fast Multimedia Library) is used *only* for rendering, window management, input handling, and multimedia.

This separation highlights how AtlasSDK can operate independently of any specific rendering framework, while still being verifiable through a visual, interactive application.

---

## Motivation

The primary goal of this project is not just to recreate Pong, but to:

* Provide a **concrete, visual testbed** for AtlasSDK features
* Validate collision detection and transform logic through real-time gameplay
* Demonstrate clean architectural separation between *engine logic* and *presentation layer*
* Showcase a minimal but complete game loop suitable for portfolio review

Using a simple and well-known game like Pong removes gameplay complexity and allows full focus on **correctness, robustness, and clarity of the underlying systems**.

---

## Architecture

The project follows a clear division of responsibilities:

### AtlasSDK

AtlasSDK is responsible for:

* Object transforms (position, size, bounding boxes)
* Collision detection and overlap testing
* World-space reasoning independent of rendering

All gameplay-relevant spatial logic (ball movement, paddle collisions, bounds checking) relies exclusively on AtlasSDK structures and algorithms.

### SFML

SFML is used strictly for:

* Window creation and management
* Rendering shapes and sprites
* Handling user input
* Audio (if enabled)

SFML objects act as a *visual representation* of the underlying AtlasSDK state and do not contain gameplay logic.

---

## Gameplay Logic

* The ball moves continuously with a velocity vector managed by AtlasSDK transforms
* Paddle collisions are detected using AtlasSDK collision primitives
* On collision:

    * The horizontal component of the ball velocity is inverted
    * The vertical component is preserved to maintain motion continuity
* Screen boundaries are also handled through AtlasSDK-based checks

This behavior makes collision outcomes easy to verify visually and helps identify edge cases or incorrect collision responses.

---

## Why Pong?

Pong was chosen intentionally because:

* Its mechanics are simple and universally understood
* Collision behavior is easy to observe and reason about
* Bugs in transforms or collision math become immediately visible
* It avoids distractions from complex assets or game logic

This makes Pong an ideal **diagnostic environment** for testing a low-level library like AtlasSDK.

---

## Technologies Used

* **C++**
* **AtlasSDK** (custom library)
* **SFML** (rendering, input, multimedia)
* **CMake** (build system)

---

## Portfolio Relevance

This project demonstrates:

* Custom engine/tooling development
* Clean separation between logic and rendering
* Practical testing strategies for low-level systems
* Ability to design small but purposeful projects
