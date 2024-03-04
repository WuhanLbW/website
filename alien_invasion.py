import random
import sys
import threading
import time

import pygame
from settings import Settings
from ship import Ship
from bullet import Bullet
from alien import Alien


class AlienInvasion:
    def __init__(self):
        pygame.init()
        self.settings = Settings()
        self.screen = pygame.display.set_mode((self.settings.screen_width, self.settings.screen_height))
        pygame.display.set_caption("Alien Invasion")
        self.ship = Ship(self)
        self.bullets = pygame.sprite.Group()
        self.ship = Ship(self)
        self.bullets = pygame.sprite.Group()
        self.aliens = pygame.sprite.Group()
        self.flag = False
        self._create_fleet()

    def run_game(self):
        while True:
            self._check_events(self)
            self.ship.update()
            self.bullets.update()
            for bullet in self.bullets.copy():
                if bullet.rect.bottom <= 0:
                    self.bullets.remove(bullet)
            self._update_aliens()
            self._update_bullets()
            self._update_screen()

            self.screen.fill(self.settings.bg_color)
            self.ship.blitme()
            pygame.display.flip()

    @staticmethod
    def _check_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.flag = True
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                self._check_keydown_events(event)
            elif event.type == pygame.KEYUP:
                self._check_keyup_events(event)

    def _fire_bullet(self):
        new_bullet = Bullet(self)
        self.bullets.add(new_bullet)

    def _create_fleet(self):
        def func_create():
            while not self.flag:
                alien = Alien(self)
                alien.x = random.randint(100, 1100)
                alien.rect.x = alien.x
                self.aliens.add(alien)
                time.sleep(1)
        t1 = threading.Thread(target=func_create)
        t1.start()

    def _update_aliens(self):
        self.aliens.update()

    def _check_keydown_events(self, event):
        if event.key == pygame.K_RIGHT:
            self.ship.moving_right = True
        elif event.key == pygame.K_LEFT:
            self.ship.moving_left = True
        elif event.key == pygame.K_q:
            sys.exit()
        elif event.key == pygame.K_SPACE:
            self._fire_bullet()

    def _update_bullets(self):
        collisions = pygame.sprite.groupcollide(
            self.bullets, self.aliens, True, True)

    def _check_keyup_events(self, event):
        if event.key == pygame.K_RIGHT:
            self.ship.moving_right = False
        elif event.key == pygame.K_LEFT:
            self.ship.moving_left = False

    def _update_screen(self):
        self.screen.fill(self.settings.bg_color)
        self.ship.blitme()
        for bullet in self.bullets.sprites():
            bullet.draw_bullet()
        self.aliens.draw(self.screen)
        pygame.display.flip()


if __name__ == "__main__":
    ai = AlienInvasion()
    ai.run_game()
