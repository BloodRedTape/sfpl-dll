#include <memory>
#include <sfpl.hpp>

#ifdef _WIN32
#define SFPL_EXPORT __declspec(dllexport)
#else
#define SFPL_EXPORT
#endif

extern "C" bool SFPL_EXPORT PlotBuilder_BuildImplNative(
        double **xs,
        double **ys,
        int *sizes,
        const char **names,
        int count,
        const char* outFilePath,
        int imageWidth, int imageHeight,
        const char* plotTitle,
        const char* xAxisName,
        const char* yAxisName)
{
    using namespace sfpl;

    std::unique_ptr<DataSource[]> sources = std::make_unique<DataSource[]>(count);
    for(int i = 0; i<count; i++){
        DataSource source;
        source.X = xs[i];
        source.Y = ys[i];
        source.Name = (char*)names[i];
        source.Count = sizes[i];

        sources[i] = source;
    }

    OutputParameters params;
    params.ImageWidth = imageWidth;
    params.ImageHeight = imageHeight;
    params.PlotTitle = (char*)plotTitle;
    params.XAxisName = (char*)xAxisName;
    params.YAxisName = (char*)yAxisName;

    return PlotBuilder::Build(sources.get(), count, (char*)outFilePath, params);
}
