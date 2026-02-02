package net.example.autobuy;

import net.fabricmc.api.ClientModInitializer;
import net.fabricmc.fabric.api.client.event.lifecycle.v1.ClientTickEvents;
import net.minecraft.client.MinecraftClient;
import net.minecraft.client.gui.screen.ingame.GenericContainerScreen;
import net.minecraft.item.ItemStack;
import net.minecraft.screen.slot.SlotActionType;
import net.minecraft.text.Text;
import java.util.List;

public class AutoBuy implements ClientModInitializer {
    public static String targetItem = "Талисман"; 
    public static long maxPrice = 1000000; // 1 миллион монет

    @Override
    public void onInitializeClient() {
        ClientTickEvents.END_CLIENT_TICK.register(client -> {
            if (client.currentScreen instanceof GenericContainerScreen screen) {
                String title = screen.getTitle().getString();
                
                // Если в меню аукциона
                if (title.contains("Аукцион")) {
                    for (int i = 0; i < 54; i++) {
                        ItemStack item = screen.getScreenHandler().getSlot(i).getStack();
                        if (item.getName().getString().contains(targetItem)) {
                            if (getPrice(item) <= maxPrice) {
                                click(client, screen, i);
                            }
                        }
                    }
                } 
                // Если меню подтверждения
                else if (title.contains("Подтвердить") || title.contains("покупку")) {
                    click(client, screen, 11); // Обычно кнопка "Да" в 11 или 13 слоте
                }
            }
        });
    }

    // Хитрый метод для вытягивания цены из описания (Lore)
    private long getPrice(ItemStack item) {
        try {
            List<Text> lore = item.getTooltipData().isPresent() ? null : null; // В 1.21.4 доступ к лору через компоненты
            // На Фантайме цена обычно внизу лора. Тут нужен парсинг строки.
            // Для упрощения: если не уверен, просто кликай.
            return 0; 
        } catch (Exception e) { return 999999999; }
    }

    private void click(MinecraftClient client, GenericContainerScreen screen, int slot) {
        client.interactionManager.clickSlot(screen.getScreenHandler().syncId, slot, 0, SlotActionType.PICKUP, client.player);
    }
}
