# PROI_PROJEKT

Autorzy:
- Jakub Kryczka
- Paweł Skorupski

## TODO
- odbijanie od ścian 
- kolizja tylko z górną wartstwą platformy
- zmniejszanie wielkości platform na wyższych poziomach
- podmiana tekstur na wyższych poziomach
- kontrola "piętra" na którym znajduje się użytkownik i wyświetlanie go
- combosy
- wyższe skoki uwarunkowane wcześniejszym rozpędzeniem się
- poprawa optymalizacji zarządzania wyświetlaniem platform
- ambitniejsza obsługa końca gry niż "window.close()" jak się spadnie
- menu startowe?
- jakieś ustawienia coś może?
- obługa kierunkowości klasy gracza i podmiana tekstur w zależności od kierunku i prędkości ruchu

## DONE
- Obsługa kolizji z kolekcją obiektów typu Tile. (Player sprawdza kolejno ze wszystkimi Tile'ami czy nie koliduje)
- Wyłączanie aplikacji ~nie~ już działa
- Klasa "Tile" (platforma)
- losowa wielkość i położenie platform -> do poprawy 
- Ruch kamery -> działa w miarę poprawnie, nie przesuwa się sama w razie bezczynności użytkownika
- Manager tekstur; każda tekstura jest załadowana w pamięci tylko raz.
