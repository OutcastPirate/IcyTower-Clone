# PROI_PROJEKT

Autorzy:
- Jakub Kryczka
- Paweł Skorupski

## (WHAT)TODO
- odbijanie od ścian 
- kolizja tylko z górną wartstwą platformy
- zmniejszanie wielkości platform na wyższych poziomach
- podmiana tekstur na wyższych poziomach
- combosy
- wyższe skoki uwarunkowane wcześniejszym rozpędzeniem się
- poprawa optymalizacji zarządzania wyświetlaniem platform
- ambitniejsza obsługa końca gry niż "window.close()" jak się spadnie ERROR goes BRRRR
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
- counter, działa ale no jest zrobiomy z płyty wiórowej i taśmy
