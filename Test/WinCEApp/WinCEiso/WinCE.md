Відмонтувати карту:
	sudo sync
	sudo eject /dev/sde
Далі роспаковуємо прошивку:
	sudo dd if=/шлях/до/WCE3.img of=/dev/sde bs=4M status=progress
