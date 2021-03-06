/*
 * Copyright (C) 2010 Pengutronix, Wolfram Sang <w.sang@pengutronix.de>
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation.
 */

#include <mach/hardware.h>
#include <mach/devices-common.h>
#include <mach/esdhc.h>

#define imx_sdhci_esdhc_imx_data_entry_single(soc, _id, hwid) \
	{								\
		.id = _id,						\
		.iobase = soc ## _ESDHC ## hwid ## _BASE_ADDR,	\
		.irq = soc ## _INT_ESDHC ## hwid,			\
	}

#define imx_sdhci_usdhc_imx_data_entry_single(soc, _id, hwid) \
	{								\
		.id = _id,						\
		.iobase = soc ## _USDHC ## hwid ## _BASE_ADDR,	\
		.irq = soc ## _INT_USDHC ## hwid,			\
	}

#define imx_sdhci_esdhc_imx_data_entry(soc, id, hwid)	\
	[id] = imx_sdhci_esdhc_imx_data_entry_single(soc, id, hwid)

#define imx_sdhci_usdhc_imx_data_entry(soc, id, hwid)	\
	[id] = imx_sdhci_usdhc_imx_data_entry_single(soc, id, hwid)

#ifdef CONFIG_SOC_IMX25
const struct imx_sdhci_esdhc_imx_data
imx25_sdhci_esdhc_imx_data[] __initconst = {
#define imx25_sdhci_esdhc_imx_data_entry(_id, _hwid)			\
	imx_sdhci_esdhc_imx_data_entry(MX25, _id, _hwid)
	imx25_sdhci_esdhc_imx_data_entry(0, 1),
	imx25_sdhci_esdhc_imx_data_entry(1, 2),
};
#endif /* ifdef CONFIG_SOC_IMX25 */

#ifdef CONFIG_SOC_IMX35
const struct imx_sdhci_esdhc_imx_data
imx35_sdhci_esdhc_imx_data[] __initconst = {
#define imx35_sdhci_esdhc_imx_data_entry(_id, _hwid)			\
	imx_sdhci_esdhc_imx_data_entry(MX35, _id, _hwid)
	imx35_sdhci_esdhc_imx_data_entry(0, 1),
	imx35_sdhci_esdhc_imx_data_entry(1, 2),
	imx35_sdhci_esdhc_imx_data_entry(2, 3),
};
#endif /* ifdef CONFIG_SOC_IMX35 */

#ifdef CONFIG_SOC_IMX50
const struct imx_sdhci_esdhc_imx_data
imx50_sdhci_esdhc_imx_data[] __initconst = {
#define imx50_sdhci_esdhc_imx_data_entry(_id, _hwid)			\
	imx_sdhci_esdhc_imx_data_entry(MX50, _id, _hwid)
	imx50_sdhci_esdhc_imx_data_entry(0, 1),
	imx50_sdhci_esdhc_imx_data_entry(1, 2),
	imx50_sdhci_esdhc_imx_data_entry(2, 3),
	imx50_sdhci_esdhc_imx_data_entry(3, 4),
};
#endif /* ifdef CONFIG_SOC_IMX50 */

#ifdef CONFIG_SOC_IMX51
const struct imx_sdhci_esdhc_imx_data
imx51_sdhci_esdhc_imx_data[] __initconst = {
#define imx51_sdhci_esdhc_imx_data_entry(_id, _hwid)			\
	imx_sdhci_esdhc_imx_data_entry(MX51, _id, _hwid)
	imx51_sdhci_esdhc_imx_data_entry(0, 1),
	imx51_sdhci_esdhc_imx_data_entry(1, 2),
	imx51_sdhci_esdhc_imx_data_entry(2, 3),
	imx51_sdhci_esdhc_imx_data_entry(3, 4),
};
#endif /* ifdef CONFIG_SOC_IMX51 */

#ifdef CONFIG_SOC_IMX53
const struct imx_sdhci_esdhc_imx_data
imx53_sdhci_esdhc_imx_data[] __initconst = {
#define imx53_sdhci_esdhc_imx_data_entry(_id, _hwid)			\
	imx_sdhci_esdhc_imx_data_entry(MX53, _id, _hwid)
	imx53_sdhci_esdhc_imx_data_entry(0, 1),
	imx53_sdhci_esdhc_imx_data_entry(1, 2),
	imx53_sdhci_esdhc_imx_data_entry(2, 3),
	imx53_sdhci_esdhc_imx_data_entry(3, 4),
};
#endif /* ifdef CONFIG_SOC_IMX53 */

#ifdef CONFIG_SOC_IMX6Q
const struct imx_sdhci_esdhc_imx_data
imx6q_sdhci_usdhc_imx_data[] __initconst = {
#define imx6q_sdhci_usdhc_imx_data_entry(_id, _hwid)			\
	imx_sdhci_usdhc_imx_data_entry(MX6Q, _id, _hwid)
	imx6q_sdhci_usdhc_imx_data_entry(0, 1),
	imx6q_sdhci_usdhc_imx_data_entry(1, 2),
	imx6q_sdhci_usdhc_imx_data_entry(2, 3),
	imx6q_sdhci_usdhc_imx_data_entry(3, 4),
};
#endif /* ifdef CONFIG_SOC_IMX6Q */

#ifdef CONFIG_SOC_MVFA5
const struct imx_sdhci_esdhc_imx_data
mvf_sdhci_esdhc_imx_data[] __initconst = {
#define mvf_sdhci_esdhc_imx_data_entry(_id, _hwid)			\
	imx_sdhci_esdhc_imx_data_entry(MVF, _id, _hwid)
	mvf_sdhci_esdhc_imx_data_entry(1, 1),
};
#endif

struct platform_device *__init imx_add_sdhci_esdhc_imx(
		const struct imx_sdhci_esdhc_imx_data *data,
		const struct esdhc_platform_data *pdata)
{
	struct resource res[] = {
		{
			.start = data->iobase,
#ifdef CONFIG_SOC_MVFA5
			.end = data->iobase + SZ_4K - 1,
#else
			.end = data->iobase + SZ_16K - 1,
#endif
			.flags = IORESOURCE_MEM,
		}, {
			.start = data->irq,
			.end = data->irq,
			.flags = IORESOURCE_IRQ,
		},
	};

	return imx_add_platform_device("sdhci-esdhc-imx", data->id, res,
			ARRAY_SIZE(res), pdata, sizeof(*pdata));
}
